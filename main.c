#include <stdio.h>
#include <stdbool.h>
#include <stdarg.h>

/*
 * static
 * 修饰函数避免外部调用
 * 修饰变量会使变量不可以被重定义，即该变量在函数执行完成时不会消失
 */
static void func(){
    static int static_num = 0;
    static_num++;//执行几次就是几
}


void test_ptr(int *a, int b){
    printf("num: %d, with ptr: %d, without ptr: %d\n",*a,a,&b);
}


void a_func_with_callback(void (*callback)(int param1)){
    callback(1);
}

void a_func_with_callback2(void (**callback)(int param1),void (callback2)(int param1)){
    printf("---------------------\nwith/without ptr: %d, %d\n",*callback,&callback2);
    (**callback)(1);
    callback2(1);
}

void callback1(int int1){
    printf("int1: %d\n",int1);
}

void callback2(int int1){
    printf("int1 ptr: %d\n",&int1);
}

void va_test(const char *fmt, ...){
    //fmt表示了参数格式，用于打印等
    va_list args;
    va_start(args, fmt);

    printf("-----------\n");


    char buf[1+ vsnprintf(NULL,0,fmt,args)];
    vsnprintf(buf,sizeof(buf),fmt,args);
    printf("%s",buf);

    // 这个宏会让arg指针后移
    printf("%s\n",va_arg(args,char[4]));
    printf("%s\n",va_arg(args,char[4]));

    va_end(args);
}





/*
 * c是面向过程语言，所有定义都是全局的
 * c关键字的权限很大，使用错误可能会读到一些不应该读到的值
 */
int main() {
    /*
     * 数字类型位数
     * 不严格区分char byte
     * stdio.h
     */
    NULL;
    printf("char:%llu\n",sizeof(char));                     // 1
    printf("unsigned char:%llu\n",sizeof(unsigned char));   // 1
    printf("short:%llu\n",sizeof(short));                   // 2
    printf("unsigned short:%llu\n",sizeof(unsigned short)); // 2
    printf("int:%llu\n",sizeof(int));                       // 4
    printf("unsigned int:%llu\n",sizeof(unsigned int));     // 4
    printf("long:%llu\n",sizeof(long ));                    // 4
    printf("unsigned long:%llu\n",sizeof(unsigned long));   // 4
    printf("float:%llu\n",sizeof(float ));                  // 4
    printf("double:%llu\n",sizeof(double ));                // 8
    printf("long int:%llu\n",sizeof(long int));             // 4
    printf("long long:%llu\n",sizeof(long long));           // 8
    printf("long double:%llu\n",sizeof(long double));       // 16


    /*
     * typedef 用于给类型定义别名
     * 也可以用来定义struct,enum
     * typedef [type] [name]
     */
    typedef enum {
        NET_INIT = 0,
        NET_CONNECTING = 1,
        NET_CONNECT_FAIL = 3,
        NET_CONNECT_SUCCESS = 4
    } E_NET_STATUS;

    /*
     * 枚举定义
     */
    enum E_NET_STATUS {
        NET_INIT_ = 0,
        NET_CONNECTING_ = 1,
        NET_CONNECT_FAIL_ = 3,
        NET_CONNECT_SUCCESS_ = 4
    };

    /*
     * 控制语句
     * if, switch, for, while
     * 这里的bool是一种数字，0是false，非0是true
     * 可以引入枚举常量 True, False...
     *
     * if(bool){}[else{}][else if(){}]
     *
     * switch(object){
     * case object:
     *     ...
     *     break;
     * default:
     *     break;
     * }
     *
     * for([initial stmt];bool;[change stmt]){}
     *
     * [do{}]while(bool){}
     */

    /*
     * 声明
     * 可以多变量声明一个数
     * int a,b = 1;
     */

    /*
     * stdbool.h
     */
    printf("%d\n",true);

    /*
     * native 数组
     * 定长
     * [type] var[] = {var1,var2..}
     * sizeof 可以返回实际长度
     */

    /*
     * 预处理器
     * 预处理器在编译前执行
     * #define [word]([param]) [any word]
     * 可以有参数
     *
     * #ifdef 如果define了则执行
     * #ifndef
     * #elif
     * #endif
     */

    /*
     * struct
     * 对象的雏形
     * 可以嵌套
     */
    struct person{
        int age;
        char name[4];
        double money;
    };

    /*
     * 指针
     * 指针指向(存储)内存地址
     * 用*定义指针
     * 在c中，通过【&】取地址符获取变量内存地址，通过【*】从内存地址获取其中的内容。
     * [type] *name = &[var]
     * printf("%d",*name) //var
     * 和java不同，变量不全是指针，其完全代表了某个内存地址。
     * 指针有自己的地址，可以嵌套指针
     * 在c中，变量用于表示数据，指针用于传递数据
     * 在函数调用中，函数参数是临时的变量，传进去的参数被复制了，改变临时变量*不会*改变传进去的参数，因此需要使用指针转递参数。
     * 数组本身就是一种指针，可以进行指针调用。
     * 指针比的结构体占用更小，如果你有很多很多，用指针显然更快。
     */
    int a = 123;
    printf("original: %d\n",&a);
    test_ptr(&a, a);
    /*
     * callback
     * 将函数作为参数
     * c可以执行函数**和**函数指针
     * callback也遵循改变临时变量*不会*改变传进去的参数的原则
     */
//    a_func_with_callback(callback1);
//    a_func_with_callback(callback2);
    void *test = &callback2; // function *callback2
    a_func_with_callback2((void (**)(int)) &test, callback2);// function **callback2
    printf("callback2 ptr: %d\n",&callback2);


    /*
     * 数据拷贝
     * [type] * [name] = ([强制转换])malloc(length) 分配一块内存
     * free(ptr) 取消分配一块内存
     * 一般用于进行数据拷贝等操作
     * ex.
     * void test(const *char data, int len){
     *      char *copied_data = (char *)malloc(len);
     *      memcpy(copied_data, data, len);
     *
     *      ...do something...
     *
     *      free(copied_data);
     * }
     */

    /*
     * stdarg.h
     * 可变参数
     * 引入后，支持可变参数
     * 例如可变参数为 int， 123，456。
     * void test(char fmt, ...){
     *      //fmt表示了参数格式，用于打印等
     *      va_list args;
     *      va_start(args, fmt);
     *
     *      ...do something... //此时 va_arg(args,int) 调用几次就会往后获取几次
     *      printf("%d\n",va_arg(args,int)); //123
     *      printf("%d\n",va_arg(args,int)); //456
     *
     *      va_end(args);
     * }
     */
    va_test("%s, %s\n","123","234");
    // 两个宏，当前函数和行号
    printf("function: %s, line: %d",__FUNCTION__ ,__LINE__);

    return 0;
}

