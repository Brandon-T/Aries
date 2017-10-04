# Aries
Forget JNI.. This library wraps JNI and attempts to port all Java constructs to C++.


# Usage

Instantiating a JVM, using `java.util.ArrayList` and `System.out.println`:
````C++
int main(int argc, const char * argv[]) {
    const char* jvmArgs[] = {"-Djava.compiler=NONE", "-Djava.class.path=."};
    StartJVM(jvmArgs, 2);
    
    if (!isJVMLoaded())
    {
        std::cerr<<"Failed to allocated JVM\n";
        return false;
    }
    
    ArrayList list;
    list.add(100);
    list.add(200);
    
    std::cout<<list.get(0)<<" "<<list.get(1)<<"\n";
    
    java::lang::System.out.println(java::lang::String("Hello World"));
}
````


JNI made easy:
````C++
JNIEXPORT void JNICALL Java_com_Example_Native_testMethod(JNIEnv* env, jobject thiz, jobject obj1, jarray obj2)
{
    ArrayList list {obj1};
    std::cout<<"Array-List Size: "<<list.size()<<"\n";
    std::cout<<"Array-List Element:"<<list.get(0)<<"\n";
    
    Array<byte> arr {obj2};
    std::cout<<"Array Size: "<<arr.length()<<"\n";
    std::cout<<"Array Element: "<<arr[0]<<"\n";
    
    std::vector<byte> vec = arr.toVector();
    byte* ptr = arr.data();
}
````
