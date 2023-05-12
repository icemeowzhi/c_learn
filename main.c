#include <stdio.h>
#include <stdbool.h>
/*
 * c是面向过程语言，所有定义都是全局的
 */
int main() {
    /*
     * 数字类型位数
     * 不严格区分char byte
     * stdio.h
     */
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
     * #define [word]([param]) [any word]
     * 预处理器在编译前执行
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
     *
     */

    return 0;
}

/*
 * static
 * 修饰函数避免外部调用
 * 修饰变量会使变量不可以被重定义，即该变量在函数执行完成时不会消失
 */
static void func(){
    static int static_num = 0;
    static_num++;//执行几次就是几
}
