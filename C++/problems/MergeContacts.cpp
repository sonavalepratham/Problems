// merge contacts
#include <bits/stdc++.h>
using namespace std;

struct contact{
  string nm;
  string bdays;
  std::vector<string> phones;
  int updated;
};

string find_root(map<string, string>& parent, string sf){
    if(sf==parent[sf])
        return sf;
    return parent[sf] = find_root(parent, parent[sf]);
}

void make_set(map<string, string>& parent, string key){
    parent[key] = key;
}

void make_union(map<string, string>&parent, string s1, string s2){
    string s1p = find_root(parent, s1);
    string s2p = find_root(parent, s2);
    if(s1p!=s2p)
        parent[s1p] = s2p;
}

void addPhonesIfNotExist(contact& c, contact* res){
    map<string, bool> mp;
    for(int i=0; i<res->phones.size(); i++){
        mp[res->phones[i]] = true;
    }
    
    for(int i=0; i<c.phones.size(); i++){
        if(!mp[c.phones[i]]){
            mp[c.phones[i]] = true;
            res->phones.push_back(c.phones[i]);
        }
    }
}

int main()
{
    map<string, string> parent;
    vector<contact> contacts;
    
    contact c1;
    c1.nm = "alice";
    c1.bdays = "05-06-2000";
    c1.phones.push_back("12345678");
    c1.phones.push_back("");
    c1.phones.push_back("(022)-2456-7890");
    c1.updated = 5;
    contacts.push_back(c1);
    
    contact c2;
    c2.nm = "Bob Person";
    c2.bdays = "";
    c2.phones.push_back("+915678192");
    c2.updated = 10;
    contacts.push_back(c2);
    
    contact c3;
    c3.nm = "Alice Weasley";
    c3.bdays = "";
    c3.phones.push_back("12345678");
    c3.phones.push_back("98765432");
    c3.updated = 20;
    contacts.push_back(c3);
    
    for(int i=0; i<contacts.size(); i++){
        string this_parent;
        for(int j=0; j<contacts[i].phones.size(); j++){
            if(contacts[i].phones[j]!=""){
                if(parent.find(contacts[i].phones[j])==parent.end() && this_parent.empty()){
                    make_set(parent, contacts[i].phones[j]);
                    this_parent = contacts[i].phones[j];
                }
                else{
                    if(this_parent.size() == 0)
                        this_parent = find_root(parent, contacts[i].phones[j]);
                    else
                        make_union(parent, contacts[i].phones[j], this_parent);
                }
            }
        }
    }

    map<string, contact*> resultMap;
    
    for(auto& it : parent){
        if(it.first == it.second){
            resultMap[it.first] = new contact();
        }
    }
    
    for(int i=0; i<contacts.size(); i++){
        string parent_root;
        for(int j=0; j<contacts[i].phones.size(); j++){
            if(contacts[i].phones[j]!="")
            {
                parent_root = find_root(parent, contacts[i].phones[j]);
                break;
            }
        }
        if(contacts[i].nm!="")
            resultMap[parent_root]->nm = contacts[i].nm;
        if(contacts[i].bdays!="")
            resultMap[parent_root]->bdays = contacts[i].bdays;
        if(contacts[i].updated > resultMap[parent_root]->updated)
            resultMap[parent_root]->updated = contacts[i].updated;
        
        addPhonesIfNotExist(contacts[i], resultMap[parent_root]);
        std::sort(resultMap[parent_root]->phones.begin(), resultMap[parent_root]->phones.end());
    }
    
    vector<contact> res;
    
    for(auto& it : resultMap){
        res.push_back(*it.second);
    }
    
    std::sort(res.begin(), res.end(), [](const contact& a, const contact& b){return a.nm<b.nm; });
    
    for(auto& it : res){
    
    cout<<it.nm<<"\n"<< (it.bdays == "" ? "empty" : it.bdays)<<"\n";
    for(auto& i : it.phones) cout<< (i=="" ? "empty" : i)<<" ";
    cout<<"\n"<<it.updated<<"\n";
    }
    return 0;
}
