#include <cstdio>
#include <cstring>
#include <locale>
#include <vector>
#include "lib/MemoryAllocator.h"

// 테스트 대상은 아래 주석과 같이 구현되어 있다. 
// 필요한 경우 아래 주석의 내용을 참고하여 테스트 케이스 입력과 테스트 코드를 작성하시오. 
// NOTE: 테스트 대상 코드는 빌드에 이미 포함되어 있으니 아래 주석을 해제하여 사용하지 마시오.

/**
 * 상수 정의
 *
#define MAX_REQ_LIMIT	(50)
#define MEMORY_SIZE		(20)
*/

/**
 * Communicator class
 * 입력된 요청을 가져오고 결과를 전송할 수 있는 인터페이스
 *
 *
class Communicator
{
public:
	/**
	 * 호출할 떄 마다 메시지 큐에 있는 요청을 하나 꺼내서 요청 값을 받아온다.
	 * @return 받은 요청 값
	 *
	virtual int getReqInput() = 0;
	
	/**
	 * 처리 결과를 전송한다.
	 * @param result 전송할 값
	 *
	virtual void send(int result) = 0;
};

*/


/*
 * [테스트 대상] 메모리 할당 모듈
 *
class MemoryAllocator {
public:
	/**
	 * 메모리를 할당하고 반납하는 모듈을 초기화
	 *
	 * @param io 할당/해제 요청을 받고 결과를 전송하는 통신 인터페이스
	 *
	MemoryAllocator(Communicator& io) : io_(io) {	}

	/**
	 * 요청을 가져와서 메모리 할당/해제 처리를 한 다음, 결과를 전송한다.
	 *
	void processRequest() {
		int command = io_.getReqInput();

		int size = abs(command  % 10);
		int id = abs(command / 10);

		int result;
		if (command < 0)
			result = deallocate(id, size);
		else
			result = allocate(id, size);

		io_.send(result);
	}
private:

	/**
	 * 할당한 메모리를 찾아서 반환할 크기만큼 해제한다.
	 * @param id 할당한 메모리 id
	 * @param size 반환할 크기
	 *
	int deallocate(int id, int size) {
		int position = findSpaceById(id);  // id로 할당된 메모리 시작 위치 반환

		for (int i = 0; i < size; ++i)
			memoryBlock[position+i] = 0;

		totalAllocated  -= size;
		return 0;
	}

	/**
	 * 크기 만큼 연속적으로 남아있는 메모리를 할당한다.
	 * @param id 할당할 메모리 id
	 * @param size 할당할 크기
	 * @return 할당에 성공하는 경우 시작하는 위치, 실패할 경우 -1
	 *
	int allocate(int id, int size) {
		int firstFreePosition = findFirstFreeSpace(size);  // size만큼 연속적으로 남아있는 공간의 첫 위치를 반환, 실패할 경우 -1
		if (firstFreePosition < 0)
			return FAILED;

		for (int i = 0; i < size; ++i)
			memoryBlock[firstFreePosition+i] = id;

		totalAllocated += size;

		return firstFreePosition;
	}

	...

	Communicator& io_;
	int memoryBlock[20] = {0, };
	int totalAllocated = 0;
}
*/



/* [문제 1. 작성 내용] */
// 테스트 케이스를 아래 배열에 추가하시오. (배열의 이름을 임의로 수정하는 경우 채점시 오답 처리됨)
// 각 테스트 케이스의 형식: { 입력 갯수, 입력 요청 값 1, 입력 요청 값 2, ... , 입력 요청 값 N }

// 테스트 케이스 예) 입력 요청값이 14, 38, -14, 22, 43, 16 순으로 오는 경우
int sampleInput_keys[MAX_REQ_LIMIT + 1] = { 6, 14, 38, -14, 22, 43, 16 };

int test_1_1_keys[MAX_REQ_LIMIT + 1] = { 9, 15, 25, 35, 45, 55, -14, 25, -11, -25 };  //TODO: 문제1.(1-1) - 최종 남은 용량이 10KB가 되는 상황
int test_1_2_keys[MAX_REQ_LIMIT + 1] = { 13, 15, 25, 35, 45, 55, -14, 25, -11, -25, 65, 75, -63,-73 };  //TODO: 문제1.(1-2) - 최종 남은 용량이 6KB이지만 연속으로 4KB인 공간이 없는 상황




/**
 * Communicator class
 * 입력된 요청을 가져오고 결과를 전송할 수 있는 인터페이스
 *
 *
class Communicator
{
public:
	/**
	 * 호출할 떄 마다 메시지 큐에 있는 요청을 하나 꺼내서 요청 값을 받아온다.
	 * @return 받은 요청 값
	 *
	virtual int getReqInput() = 0;
	
	/**
	 * 처리 결과를 전송한다.
	 * @param result 전송할 값
	 *
	virtual void send(int result) = 0;
};

*/

namespace{
    struct FakeInput: public Communicator
    {
        FakeInput(int keys[]):input(keys){}
        virtual void send(int result) override
        {
            lastData = result;
        };
        virtual int getReqInput() override
        {
            return input[cnt++];
        }
        int getLastSent(){
            return lastData;
        }        
    private:
        int* input;
        int cnt=0;
        int lastData=0;
    };
}
/*
MemoryAllocator
processRequest()
*/
// [문제2. 작성 내용]
// 원하는 요청 값을 전달할 수 있도록 fake/stub을 구현하여 제시된 상황을 재현하는 테스트 코드를 작성하시오.
// NOTE: 답안 코드 실행 중 메모리 누수가 발생하면 오답 처리됨



void test_2_1(void)
{
    int TestInput[] = { 12, 24, 38, -38, -12 };  //TODO: 문제1.(1-1) - 최종 남은 용량이 10KB가 되는 상황
    FakeInput input(TestInput);
    MemoryAllocator MA(input);
    for(auto k:TestInput){
        MA.processRequest();
	}
	// TODO: // 문제2.(2-1)
	// 요청 값의 입력이 다음의 순서대로 발생하는 상황: 12 -> 24 -> 38 -> -38 -> -12
}

void test_2_2(void)
{
    int TestInput[] = { 18, 21, -18, 33, 41, -33 };  //TODO: 문제1.(1-1) - 최종 남은 용량이 10KB가 되는 상황    
    FakeInput input(TestInput);
    MemoryAllocator MA(input);
    for(auto k:TestInput){
        MA.processRequest();
	}
	// TODO: 문제2.(2-2) 
	// 요청 값의 입력이 다음의 순서대로 발생하는 상황: 18 -> 21 -> -18 -> 33 -> 41 -> -33
}

// 다음과 같이 정의된 TestCase를 입력 받아서 
// 해당 input으로 요청값이 발생하는 상황을 재현하고, 마지막으로 전송되는 결과를  expected와 비교하여 검증하는 코드를 구현하라.
// 단, expected와 같은지 확인하는 verify API는 반드시 아래의 API를 이용하도록 한다.

//void assertEquals(int expected, int actual);


void test_2_3(std::vector<int> inputReqs, int expected) {
	// TODO: 문제 2-3
    FakeInput input(inputReqs.data());
    MemoryAllocator MA(input);
    for(auto k:inputReqs){
        MA.processRequest();
		}    
	assertEquals(expected, input.getLastSent());
}

/* [문제 3. 작성 내용] */
// 기능 요구사항 대로 처리할 수 없는 모든 예외 상황을 식별해서 해당 상황을 표현하는 테스트 케이스를 아래 배열에 추가하시오. (배열의 이름을 임의로 수정하는 경우 채점시 오답 처리됨)
// 제시된 형식에 맞지 않는 입력은 없다고 가정하고, 
// 예외의 종류마다 1개씩 구분하여 추가한다.

/* 테스트 케이스의 형식:
{
	4,
	{
		{ 5, 입력 요청 값 1, 입력 요청 값 2, ..., 입력 요청 값 N },
		...
		{ 입력 갯수, 입력 요청 값 1, 입력 요청 값 2, ..., 입력 요청 값 N },
	}
};
*/

typedef int InputSequence[MAX_REQ_LIMIT];

struct ExceptionalCases {
	int numberOfCases;
	InputSequence inputKeys[10];
};


// TODO: 문제 3
ExceptionalCases test_3_cases = {

	3, /* FIXME */
	{
		{ 5,  15, 15, 15, 15, 15},
		{ 5,  -15, -15, -15, -15, -15},
        { 2,  115, 1515}
	}
};


// 참고용으로 실행하고 싶은 코드가 있다면 아래 main()에 작성하여 활용할 수 있다.
// main 함수의 코드는 채점과 관련이 없다.
int main()
{
	printTestInputResult("Sample Input", sampleInput_keys);
	printTestInputResult("Test_1_1 Input", test_1_1_keys);
	printTestInputResult("Test_1_2 Input", test_1_2_keys);

	test_2_1();
	test_2_2();

	return 0;
}