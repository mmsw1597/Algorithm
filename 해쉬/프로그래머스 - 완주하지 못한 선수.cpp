#include <string>
#include <vector>
#include <map>
#include <utility> //pair 사용


using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    
    multimap<string,int> m; //중복을 허용해야 하므로 multimap 사용
    for(int i=0; i<participant.size(); i++)
        m.insert(make_pair(participant[i],i));
    
    for(int i=0; i<completion.size(); i++)
        m.erase(m.find(completion[i])); //find를 안쓰고 erase를 하면 해당 key값을 가진 원소를 모두 삭제하기 때문에 find 사용
    

    return m.begin() -> first;
}
