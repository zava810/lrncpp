#include<mutex>
#include <thread>
#include<iostream>
#include<string>
using namespace std;
class Singleton
{
private: static Singleton * pinstance_; static mutex mutex_;
protected:
    Singleton(const string value): value_(value) {}
    ~Singleton() {}
    string value_;
public:
    Singleton(Singleton &other) = delete;
    void operator=(const Singleton &) = delete;
    static Singleton *GetInstance(const string& value);
    void SomeBusinessLogic()
    {
        // ...
    }
    string value() const{ return value_; }
};

/** * Static methods should be defined outside the class.  */
Singleton* Singleton::pinstance_{nullptr};
mutex Singleton::mutex_;
Singleton *Singleton::GetInstance(const string& value)
{
    lock_guard<mutex> lock(mutex_);
    if (pinstance_ == nullptr) { pinstance_ = new Singleton(value); }
    return pinstance_;
}

void ThreadFoo(){
    // Following code emulates slow initialization.
    this_thread::sleep_for(chrono::milliseconds(1000));
    Singleton* singleton = Singleton::GetInstance("FOO");
    cout << singleton->value() << "\n";
}

void ThreadBar(){
    // Following code emulates slow initialization.
    this_thread::sleep_for(chrono::milliseconds(1000));
    Singleton* singleton = Singleton::GetInstance("BAR");
    cout << singleton->value() << "\n";
}

int main()
{
    cout <<"If you see the same value, then singleton was reused (yay!\n" <<
                "If you see different values, then 2 singletons were created (booo!!)\n\n" <<
                "RESULT:\n";
    thread t1(ThreadFoo);
    thread t2(ThreadBar);
    t1.join();
    t2.join();

    return 0;
}
