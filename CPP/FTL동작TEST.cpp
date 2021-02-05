#include <cstdio>
#include <cstring>
#include <vector>
#include <locale>

#include "./lib/FTL.h"

// 테스트 대상은 아래 주석과 같이 구현되어 있다. 
// 필요한 경우 아래 주석의 내용을 참고하여 테스트 케이스 입력과 테스트 코드를 작성하시오. 
// NOTE: 테스트 대상 코드는 빌드에 이미 포함되어 있으니 아래 주석을 해제하여 사용하지 마시오.


/**
 * 상수 정의
 *
#define MAX_REQ_LIMIT	(50)
#define MAX_BLOCK_COUNT	(8)

#define W 1 // Write(쓰기)
#define M 2 // Modify(수정)
#define R 3 // Read(읽기)
#define D 4 // Delete(삭제)


/**
 * Request class
 * 요청 데이터 구조
 *z
struct Request {
	int operation;  // W, M, R, D 중 하나 
	int block;
	int length;
};



/**
 * FlashMemory 인터페이스
 * 플래시 메모리의 물리 블록에 읽기, 쓰기, 삭제 동작을 수행하도록 지시하는 인터페이스
 *
 *
class FlashMemory
{
public:
	virtual bool write(int blockNumber/*, const BlockData* data * /) = 0; // 데이터는 편의상 생략 
	virtual bool read(int blockNumber/*, BlockData* data * /) = 0; // 데이터는 편의상 생략 
	virtual bool erase(int blockNumber) = 0;
};
*/



/**
 * [테스트 대상] FTL class
 * 논리 블록에 대한 요청을 받아 상황에 따라 적절한 물리 블록에 요청 동작을 수행 (테스트 대상)
 *
 *
class FTL
{
public:
	/**
	 * FTL 모듈을 초기화
	 * 
	 * @param flashMemory 플래시 메모리의 물리 블록에 동작을 지시하는 제어 인터페이스
	 *
	FTL(FlashMemory& flashMemory) : flashMemory_(flashMemory) {
		resetStatus();
	}

	void resetStatus()
	{
		for (int i = 0; i < MAX_BLOCK_COUNT; i++) {
			mappingStatus_[i] = -1;
			physicalStatus_[i] = 0;
			eraseStatus_[i] = 0;
		}
		freeBlockCount_ = MAX_BLOCK_COUNT;
	}

	/**
	 * 요청한 논리 블록에 쓰기 동작을 수행
	 * @param start 쓰기 동작을 시작할 논리 블록 번호
	 * @param length 쓰기 동작을 수행할 블록 갯수
	 *
	bool writeBlock(int start, int length)
	{
		if (!hasFreeLogicalBlock(start, length))
			return false;

		int firstFreeBlock = findFreePhysicalBlock(length);
		if (firstFreeBlock < 0)
			return false;

		int block = firstFreeBlock;
		for (int i = start; i < start + length; i++) {
			eraseStatus_[block]++;
			mappingStatus_[i] = block;
			physicalStatus_[block] = 1;
			block++;
		}

		freeBlockCount_ -= length;
		
		for (int i = 0; i < length; ++i) {
			flashMemory_.erase(mappingStatus_[start + i]);
			flashMemory_.write(mappingStatus_[start + i]);
		}

		return true;
	}

	/**
	 * 요청한 논리 블록을 수정하는 동작을 수행
	 * @param start 수정 동작을 시작할 논리 블록 번호
	 * @param length 수정 동작을 수행할 블록 갯수
	 *
	bool modifyBlock(int start, int length)
	{
		if (!isUsedLogicalBlock(start, length))
			return false;

		int firstFreeBlock = findFreePhysicalBlock(length);
		if (firstFreeBlock < 0)
			return false;

		int block = firstFreeBlock;
		for (int i = start; i < start + length; i++) {
			eraseStatus_[block]++;
			physicalStatus_[mappingStatus_[i]] = 0;
			mappingStatus_[i] = block;
			physicalStatus_[block] = 1;
			block++;
		}

		for (int i = 0; i < length; ++i) {
			flashMemory_.erase(mappingStatus_[start + i]);
			flashMemory_.write(mappingStatus_[start + i]);
		}
		
		return true;
	}

	/**
	 * 요청한 논리 블록의 내용을 읽어오는 동작을 수행
	 * @param start 읽기 동작을 시작할 논리 블록 번호
	 * @param length 읽기 동작을 수행할 블록 갯수
	 *
	bool readBlock(int start, int length)
	{
		if (!isUsedLogicalBlock(start, length))
			return false;

		for (int i = 0; i < length; ++i) {
			flashMemory_.read(mappingStatus_[start + i]);
		}

		return true;
	}

	/**
	 * 사용하지 않을 논리 블록을 해제
	 * @param start 삭제 동작을 시작할 논리 블록 번호
	 * @param length 삭제 동작을 수행할 블록 갯수
	 *
	bool deleteBlock(int start, int length)
	{
		if (!isUsedLogicalBlock(start, length))
			return false;

		for (int i = start; i < start + length; i++) {
			physicalStatus_[mappingStatus_[i]] = 0;
			mappingStatus_[i] = -1;
		}
		freeBlockCount_ += length;

		return true;
	}

	int getFreeBlockCount() const
	{
		return freeBlockCount_;
	}

private:
	// start 부터 count 개의 논리 블록이 모두 사용 중이면 true
	bool isUsedLogicalBlock(int start, int count)
	{
		for (int i = start; i < start + count; i++) {
			if (mappingStatus_[i] == -1) {
				return false;
			}
		}
		return true;
	}

	// start 부터 count 개의 논리 블록이 모두 비어 있으면 true
	bool hasFreeLogicalBlock(int start, int count)
	{
		for (int i = start; i < start + count; i++) {
			if (mappingStatus_[i] != -1) {
				return false;
			}
		}
		return true;
	}

	// count 개의 연속된 비어 있는 물리 블록을 앞에서부터 검색하여 찾으면 시작하는 물리 블록을 반환, 못 찾으면 -1을 반환
	int findFreePhysicalBlock(int count)
	{
		for (int i = 0; i <= MAX_BLOCK_COUNT - count; i++) {
			int j = 0;
			for (j = i; j < i + count; j++) {
				if (physicalStatus_[j] == 1) break;
			}
			if (j == i + count) {
				return i;
			}
		}
		
		return -1;
	}

protected:
	FlashMemory& flashMemory_;

	int mappingStatus_[MAX_BLOCK_COUNT];
	int physicalStatus_[MAX_BLOCK_COUNT];
	int eraseStatus_[MAX_BLOCK_COUNT];
	int freeBlockCount_ = MAX_BLOCK_COUNT;
};



#define W 1 // Write(쓰기)
#define M 2 // Modify(수정)
#define R 3 // Read(읽기)
#define D 4 // Delete(삭제)


/**
 * Request
 * 요청 입력 데이터 구조
 *
struct Request {
	int operation;  // W, M, R, D 중 하나 
	int block;
	int length;
};
*/



/* [문제 1. 작성 내용] */
// 테스트 케이스를 아래 배열에 추가하시오. (배열의 이름을 임의로 수정하는 경우 채점시 오답 처리됨)
// 각 테스트 케이스의 형식: { 입력 요청 값 1, 입력 요청 값 2, ... , 입력 요청 값 N }

// 테스트 케이스 예) : 문제에서 설명한 동작 예제
// 요청이 {W,0,6}, {D,3,2}, {M,1,2} ,{R,0,3} 순으로 입력되는 경우
std::vector<Request> sampleInput_reqs = { {W,0,6}, {D,3,2}, {M,1,2} ,{R,0,3} };

//TODO: 문제1.(1-1) - 최종적으로 비어 있는 물리 블록이 0개가 되는 상황
std::vector<Request> test_1_1_reqs = {{W,0,8} };

//TODO: 문제1.(1-2) - 최종적으로 비어 있는 물리 블록이 4개이고, 0번 ~ 3번 물리 블록이 비어 있는 상황
std::vector<Request> test_1_2_reqs = {{W,0,8}, {D,0,4}   };

//TODO: 문제1.(1-3) - 최종적으로 물리 블록의 지운 회수가 모두 2가 되는 상황
std::vector<Request> test_1_3_reqs = { {W,0,8}, {D,3,2}, {W,0,8} };

//TODO: 문제1. (1-4) - FTL의 모듈 코드에 대해서 statement coverage 100%가 만족되는 요청 입력
std::vector<Request> test_1_4_reqs = { {R,0,8},{W,0,6}, {D,0,6}, {M,1,2}, {W,0,4}, {M,0,4}, {D,4,4}, {R,0,3}, {W,0,3}, {R,0,3}, {W,0,6}, {W,5,2}, {W,0,2},{R,0,8},{R,7,1},{M,7,1}};



// [문제2. 작성 내용]
// NOTE: 답안 코드 실행 중 메모리 누수나 런타임 에러가 발생하면 오답 처리됨



void test_2_1()
{
    
	// TODO: // 문제2.(2-1)
	// 요청이 다음의 순서대로 발생하는 상황: W,1,4 -> R,2,2 -> M,4,1 -> D,1,1
}

void test_2_2()
{
	// TODO: 문제2.(2-2) 
	// 요청이 다음의 순서대로 발생하는 상황: W,0,8 -> D,6,2 -> M,4,2 -> R,2,2 -> D,2,2
}







// [문제3. 작성 내용]
/**
 * FTLExt class
 * 논리 블록에 대한 요청을 받아 처리 (테스트 대상)
 */
class FTLExt
{
public:
	/**
	 * FTLExt 모듈을 초기화
	 * @param flashMemory 플래시 메모리의 물리 블록에 동작을 지시하는 제어 인터페이스
	 */
	FTLExt(FlashMemory& flashMemory) : flashMemory_(flashMemory) {
		resetStatus();
	}

	void resetStatus()
	{
		for (int i = 0; i < MAX_BLOCK_COUNT; i++) {
			mappingStatus_[i] = -1;
			physicalStatus_[i] = 0;
			eraseStatus_[i] = 0;
		}
		freeBlockCount_ = MAX_BLOCK_COUNT;
	}

	/**
	 * 요청한 논리 블록에 쓰기 동작을 수행
	 * @param start 쓰기 동작을 시작할 논리 블록 번호
	 * @param length 쓰기 동작을 수행할 블록 갯수
	 */
	bool writeBlock(int start, int length)
	{
		if (!hasFreeLogicalBlock(start, length))
			return false;

		int firstFreeBlock = findFreePhysicalBlock(length);
		if (firstFreeBlock < 0)
			return false;

		int block = firstFreeBlock;
		for (int i = start; i < start + length; i++) {
			eraseStatus_[block]++;
			mappingStatus_[i] = block;
			physicalStatus_[block] = 1;
			block++;
		}

		freeBlockCount_ -= length;
		
		for (int i = 0; i < length; ++i) {
			flashMemory_.erase(mappingStatus_[start + i]);
			flashMemory_.write(mappingStatus_[start + i]);
		}

		return true;
	}

	/**
	 * 요청한 논리 블록을 수정하는 동작을 수행
	 * @param start 수정 동작을 시작할 논리 블록 번호
	 * @param length 수정 동작을 수행할 블록 갯수
	 */
	bool modifyBlock(int start, int length)
	{
		if (!isUsedLogicalBlock(start, length))
			return false;

		int firstFreeBlock = findFreePhysicalBlock(length);
		if (firstFreeBlock < 0)
			return false;

		int block = firstFreeBlock;
		for (int i = start; i < start + length; i++) {
			eraseStatus_[block]++;
			physicalStatus_[mappingStatus_[i]] = 0;
			mappingStatus_[i] = block;
			physicalStatus_[block] = 1;
			block++;
		}

		for (int i = 0; i < length; ++i) {
			flashMemory_.erase(mappingStatus_[start + i]);
			flashMemory_.write(mappingStatus_[start + i]);
		}
		
		return true;
	}

	/**
	 * 요청한 논리 블록의 내용을 읽어오는 동작을 수행
	 * @param start 읽기 동작을 시작할 논리 블록 번호
	 * @param length 읽기 동작을 수행할 블록 갯수
	 */
	bool readBlock(int start, int length)
	{
		if (!isUsedLogicalBlock(start, length))
			return false;

		for (int i = 0; i < length; ++i) {
			flashMemory_.read(mappingStatus_[start + i]);
		}

		return true;
	}

	/**
	 * 사용하지 않을 논리 블록을 해제
	 * @param start 삭제 동작을 시작할 논리 블록 번호
	 * @param length 삭제 동작을 수행할 블록 갯수
	 */
	bool deleteBlock(int start, int length)
	{
		if (!isUsedLogicalBlock(start, length))
			return false;

		for (int i = start; i < start + length; i++) {
			physicalStatus_[mappingStatus_[i]] = 0;
			mappingStatus_[i] = -1;
		}
		freeBlockCount_ += length;

		return true;
	}

private:
	bool isUsedLogicalBlock(int start, int count)
	{
		for (int i = start; i < start + count; i++) {
			if (mappingStatus_[i] == -1) {
				return false;
			}
		}
		return true;
	}

	// start 부터 count 개의 논리 블록이 모두 비어 있으면 true
	bool hasFreeLogicalBlock(int start, int count)
	{
		for (int i = start; i < start + count; i++) {
			if (mappingStatus_[i] != -1) {
				return false;
			}
		}
		return true;
	}

	// count 개의 연속된 비어 있는 물리 블록을 앞에서부터 검색하여 찾으면 시작하는 물리 블록을 반환, 못 찾으면 -1을 반환
	int findFreePhysicalBlock(int count)
	{
		for (int i = 0; i <= MAX_BLOCK_COUNT - count; i++) {
			int j = 0;
			for (j = i; j < i + count; j++) {
				if (physicalStatus_[j] == 1) break;
			}
			if (j == i + count) {
				return i;
			}
		}

		return -1;
	}

protected:
	FlashMemory& flashMemory_;

	int mappingStatus_[MAX_BLOCK_COUNT];
	int physicalStatus_[MAX_BLOCK_COUNT];
	int eraseStatus_[MAX_BLOCK_COUNT];
	int freeBlockCount_ = MAX_BLOCK_COUNT;
};


// 참고용으로 실행하고 싶은 코드가 있다면 아래 main()에 작성하여 활용할 수 있다.
// main 함수의 코드는 채점과 관련이 없다.
int main()
{
	printTestInputResult("Sample Input", sampleInput_reqs);
	printTestInputResult("Test_1_1 Input", test_1_1_reqs);
	printTestInputResult("Test_1_2 Input", test_1_2_reqs);
	printTestInputResult("Test_1_3 Input", test_1_3_reqs);

	test_2_1();
	test_2_2();



	return 0;
}
