#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <memory>
#include <windows.h>
#include <queue>
#include <thread>
#include <chrono>
#include "Queue.h"

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Queue<int> queue_1;
	Queue<int> queue_2;
	Queue<int> queue_3;
	std::thread t1([&]()
	{
	queue_1.pushQueue(45);
	queue_1.pushQueue(55);
	queue_1.pushQueue(35);
	queue_1.pushQueue(15);
	queue_1.pushQueue(5);
	queue_1.pushQueue(95);
	queue_1.frontQueue();
	queue_1.popQueue();
	queue_1.emptyQueue();
	});
	std::thread t2([&]()
	{
	std::this_thread::sleep_for(std::chrono::milliseconds(5000));
	queue_2.pushQueue(7);
	queue_2.pushQueue(37);
	queue_2.pushQueue(77);
	queue_2.pushQueue(17);
	queue_2.pushQueue(47);
	queue_2.pushQueue(167);
	queue_2.frontQueue();
	queue_2.popQueue();
	queue_2.emptyQueue();
	});
	
	t1.join();
	t2.join();




}

	
	
	
	
	
	
	
	
	
	
	

