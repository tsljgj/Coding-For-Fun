#include<bits/stdc++.h>
using namespace std;
struct test{
		int math;
		int pe;
		
		test(int num=10000,int num2=90):math(num),pe(num2){   //此函数用来设施一个struct的默认值，函数名与struct名一致 
//			math=num;
//			pe=num2;
		}
		
//		operator =(const test b) const{
//			cout<<"???"<<endl;                            //可以写 
//			return max(this->math,b.math);        //=,>,<,!=等返回的是bool 
//												  //this->math指这个结构体的某一元素 
//		}
test operator=(test a) {    //"="只能定义在内部 
}
	}a[2];
int main(){
	
	
	
	
//	a[1].math=100;
//	a[1].pe=9;
	
//	a[1].math=100;
//	a[1].pe=90;

//	a[0].math=1000;
//	a[0].pe=90;
	
//	cout<<a[1].math<<" "<<a[1].pe<<" "<<(a[1]=a[0])<<endl;
	return 0;
}
