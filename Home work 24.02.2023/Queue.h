#pragma once
#include <iostream>
#include <queue>
#include <mutex>
#include <thread>

template <class T> class Queue {
public:
	void pushQueue(const T& el) {
		std::lock_guard<std::mutex> lock(_mutex);
		std::cout << "Add element" << std::endl;
		q.push(el);
	}
	void popQueue() {
		_mutex.lock();
		std::cout << "Remove element" << std::endl;
		if (!q.empty()){
			q.pop();
		}
		else
			std::cout << "The queue is empty" << std::endl;
		_mutex.unlock();
	}
	void frontQueue() {
		_mutex.lock();
		if (!q.empty()){
		std::cout << "First element in the queue " << q.front() << std::endl;
		}
		else
			std::cout << "The queue is empty" << std::endl;
		_mutex.unlock();
	}
	void emptyQueue() {
		std::lock_guard<std::mutex> lock(_mutex);
		if (q.empty()){
			std::cout << "The queue is empty" << std::endl;
		}
		else
			std::cout << "Queue is not empty" << std::endl;
	}
	void printQueue(){
		std::lock_guard<std::mutex> lock(_mutex);
		std::cout << "Element Queue " << std::endl;
		while (!q.empty())
		{
			std::cout << q.front() << " ";
			q.pop();
		}
		std::cout << std::endl;
	}
private:
	std::queue<T> q;
	std::mutex _mutex;
	
};