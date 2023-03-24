class FooBar {
    //me honestly be noob at threading/mutex problems
private:
    int n;
    std::mutex mtx;
    std::condition_variable cv;
    bool fooTurn = true;
public:
   FooBar(int n) {
        this->n = n;
    }

    void foo(function<void()> printFoo) {
        for (int i = 0; i < n; i++) {
            std::unique_lock<std::mutex> lock(mtx);
            cv.wait(lock, [this] { return fooTurn; });
			
        	printFoo();
			
            fooTurn = false;
            cv.notify_one();
        }
    }

    void bar(function<void()> printBar) {
        for (int i = 0; i < n; i++) {
            std::unique_lock<std::mutex> lock(mtx);
            cv.wait(lock, [this] { return !fooTurn; });
			
        	printBar();
			
            fooTurn = true;
            cv.notify_one();
        }
    }
};