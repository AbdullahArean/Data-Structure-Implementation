#include<bits/stdc++.h>

using namespace std;
class Student{
    public:
    int age;
    string name;

    Student(int age, string name){
        this->age= age;
        this->name = name;
    }
    // bool operator< (const Student otherStudent) const{
    //     return age> otherStudent.age;
    // }

};
struct comparator
{
    bool operator()(Student a, Student b){
        return a.age<b.age;
    }
};

int main()
{
    priority_queue<Student, vector<Student>, comparator> pq;
    //priority_queue<Student>pq;
    pq.push(Student(12, "asrean"));

    pq.push(Student(12, "sfsdarean"));

    pq.push(Student(1332, "sdsfarean"));

    pq.push(Student(13332, "areafsn"));

    pq.push(Student(1332, "afsrsdfeansf"));
    while(!pq.empty()){
        cout<<pq.top().name<<" "<<pq.top().age<<endl;
        pq.pop();
    }
    return 0;
}