#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <algorithm>
using namespace std;

std::ofstream result("grader_result.txt"); // ตัวเปิดไฟล์ "grader_result.txt"
void correct() {
	::result << 'P'; // เขียนไฟล์นั้นว่า "P"
	::exit(0);
}
void wrong() {
	::result << 'W'; // เขียนไฟล์นั้นว่า "W"
	::exit(0);
}
int main(int argc, char* argv[]) {
	std::ifstream sol(argv[1]); 	//อ่าน .sol ไฟล์จาก argv ข้อที่ 1
	std::ifstream inp(argv[2]); 	//อ่าน .in ไฟล์จาก argv ข้อที่ 2
	std::ifstream cod(argv[3]); 	//อ่าน code จากไฟล์ที่น้องส่ง จาก argv ข้อที่ 3
	std::ifstream out("output.txt");//อ่าน output ที่น้อง Output ออกมา

    string ans, real;
    out >> ans;
    sol >> real;
    if(ans!=real) wrong();
    else{
        string s;
        out >> s;
        int n;
        inp >> n;
        if(s.length()!=n)wrong();
        vector<int> dp(n+5, 0);
        for(int i=0; i<n; i++){
            int pow;
            inp >> pow;
            int l, r;
            if(s[i]=='L'){
                l=max(0, i-pow);
                r=max(0, i-1);
            }
            if(s[i]=='R'){
                l=min(n-1, i+1);
                r=min(n-1, i+pow);
            }
            dp[l]++;
            dp[r+1]--;
        }
        bool flag=1;
        if(dp[0]==0)wrong();
        for(int i=1; i<n; i++){
            dp[i]+=dp[i-1];
            if(dp[i]==0){
                flag=0;
                break;
            }
        }
        if(flag==0)wrong();
    }
    correct();
}