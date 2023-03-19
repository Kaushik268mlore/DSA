class Foo {
// private:  ///okay i recieved tle for this solution...lol
//     int count;
//     pthread_mutex_t count_mutex;
//     pthread_cond_t count_threshold_cv;
// public:
    
//     //okay so i've learnt about p_threads before and how they work and will implement them
//     Foo() {
//         pthread_mutex_init(&count_mutex, NULL);
//         pthread_cond_init (&count_threshold_cv, NULL);
//         count = 0;
//     }

//     void first(function<void()> printFirst) {
        
//         // printFirst() outputs "first". Do not change or remove this line.
//         printFirst();
//         pthread_mutex_lock(&count_mutex);
//         count++;
//         pthread_cond_signal(&count_threshold_cv);
//         pthread_mutex_unlock(&count_mutex);
//     }

//     void second(function<void()> printSecond) {
        
//         // printSecond() outputs "second". Do not change or remove this line.
//         pthread_mutex_lock(&count_mutex);
//         while (count < 1) {
//             pthread_cond_wait(&count_threshold_cv, &count_mutex);
//         }
//         printSecond();
//         count++;
//         pthread_cond_signal(&count_threshold_cv);
//         pthread_mutex_unlock(&count_mutex);
//     }

//     void third(function<void()> printThird) {
        
//         // printThird() outputs "third". Do not change or remove this line.
//         pthread_mutex_lock(&count_mutex);
//       while (count < 2) {
//           pthread_cond_wait(&count_threshold_cv, &count_mutex);
//       }
//         printThird();
//         count++;
//       pthread_cond_signal(&count_threshold_cv);
//       pthread_mutex_unlock(&count_mutex);
//     }
public:   
    bool firstRan = false;
    bool secondRan = false;
    pthread_mutex_t m = PTHREAD_MUTEX_INITIALIZER;
    pthread_cond_t cv1 = PTHREAD_COND_INITIALIZER;
    pthread_cond_t cv2 = PTHREAD_COND_INITIALIZER;
	
    Foo() { }

    void first(function<void()> printFirst) {
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        
        pthread_mutex_lock(&m);
        firstRan = true;
        pthread_mutex_unlock(&m);
        pthread_cond_broadcast(&cv1);
    }

    void second(function<void()> printSecond) {
        pthread_mutex_lock(&m);
		
        while (!firstRan) { 
            pthread_cond_wait(&cv1, &m);
        }
		
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        
        secondRan = true;
        pthread_mutex_unlock(&m);
        pthread_cond_broadcast(&cv2);
    }

    void third(function<void()> printThird) {
        pthread_mutex_lock(&m);
		
        while (!firstRan) {
             pthread_cond_wait(&cv1, &m);
        }
        while (!secondRan) {
             pthread_cond_wait(&cv2, &m);
        }
		
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
        pthread_mutex_unlock(&m);
    }
};