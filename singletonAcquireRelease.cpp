// singletonAcquireRelease.cpp

#include <atomic>
#include <iostream>
#include <future>
#include <mutex>
#include <thread>
using namespace std
constexpr auto ten_mill= 10000000;

class cl_singleton{
public:
  static cl_singleton* getInstance(){
    cl_singleton* singleton_instance= instance.load();
    if ( !singleton_instance ){
      lock_guard<mutex> myLock(my_mutex);
      singleton_instance= instance.load();
      if( !singleton_instance ){
        singleton_instance= new cl_singleton();
        instance.store(singleton_instance);
      }
    }   
    // volatile int dummy{};
    return singleton_instance;
  }
private:
  cl_singleton()= default;
  ~cl_singleton()= default;
  cl_singleton(const cl_singleton&)= delete;
  cl_singleton& operator=(const cl_singleton&)= delete;

  static atomic<cl_singleton*> instance;
  static mutex my_mutex;
};


std::atomic<cl_singleton*> cl_singleton::instance;
std::mutex cl_singleton::my_mutex;

std::chrono::duration<double> getTime(){

  auto begin= std::chrono::system_clock::now();
  for ( size_t i= 0; i <= ten_mill; ++i){
       cl_singleton::getInstance();
  }
  return std::chrono::system_clock::now() - begin;
  
};


int main(){

    auto fut1= std::async(std::launch::async,getTime);
    auto fut2= std::async(std::launch::async,getTime);
    auto fut3= std::async(std::launch::async,getTime);
    auto fut4= std::async(std::launch::async,getTime);
    
    auto total= fut1.get() + fut2.get() + fut3.get() + fut4.get();
    
    std::cout << total.count() << std::endl;

}
