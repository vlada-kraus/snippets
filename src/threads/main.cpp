#include <iostream>
#include <thread>
#include <mutex>
#include <vector>

int i = 0;
std::mutex m;

void hello()
{
	std::unique_lock<std::mutex> lock(m);
	//m.lock();
	++i;
	std::cout << i << "Hello world!" << std::endl;
	//m.unlock();
}

int main()
{
	std::vector<std::thread> ts;
	for (int i = 0; i < 10; ++i)
		ts.push_back(std::thread(hello));
	
	for (auto &t : ts)
		t.join();
}