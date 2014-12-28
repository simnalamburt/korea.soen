#include<stdio.h>
#include<string>
#include<vector>
#include<iostream>
#include<utility>;
using namespace std;
pair<string, string>pair1;
vector<pair<string, string>> whitebook;
string temp;
string temp1;

void search(){
  int i, save,count=0;
  printf("이름을 입력하시오");
  cin >> temp;
  for(i=0; i< whitebook.size(); i++){
    if(whitebook[i].first.compare(temp)==0){
      count=count+1;
      save=i;
    }
  }
  if(count==0) printf("해당 이름의 전화번호는 존재하지 않습니다.");
  else if(count==1){
    cout<<whitebook[save].second<< "\n";
  }
  else printf("error: 해당 이름에 2개 이상의 전화번호가 저장되어 있습니다.");
}
void AddPhone(){
  int i, save,count=0;
  printf("이름을 입력하시오");
  cin >> temp;
  for(i=0; i< whitebook.size(); i++){
    if(whitebook[i].first.compare(temp)==0){
      count=count+1;
      save=i;
    }
  }
  if(count!=0) printf("해당 이름의 전화번호는 이미 저장되어있습니다.");
  else{
    printf("해당 이름의 전화번호를 입력해주십시오.");
    cin >> temp1;
    pair1.first=temp;
    pair1.second=temp1;
    whitebook.push_back(pair1);
    printf("저장이 완료되었습니다.");
  }
}
void Delete(){
  int i, save,count=0;
  printf("이름을 입력하시오");
  cin >> temp;
  for(i=0; i< whitebook.size(); i++){
    if(whitebook[i].first.compare(temp)==0){
      count=count+1;
      save=i;
    }
  }
  if(count==0) printf("해당 이름의 전화번호는 존재하지 않습니다.");
  if(count==1){
    whitebook.erase(whitebook.begin()+save);
    printf("삭제가 완료되었습니다.");
  }
}
int main(){
  int a;
  while(1){
    printf("무엇을 하시겠습니까\n");
    printf("1. Search\n");
    printf("2. Add\n");
    printf("3. Delete\n");
    printf("4. Finish\n");
    scanf("%d", &a);
    if(a==1) search();
    else if(a==2) AddPhone();
    else if(a==3) Delete();
    else if(a==4) return 0;
    else printf("유효한 입력이 아닙니다.\n");
  }
}
