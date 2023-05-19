
#include <bits/stdc++.h>
using namespace std;

void FCFS(vector<int> p,int head)
{
    int seek_time=0;
            cout<<"\n Next position"<<"             Head"<< "  Traversed tracks\n";
    for(auto current_head:p)
    {
        seek_time+=abs(current_head - head);

        cout<<"      "<<setw(10)<<current_head<<"           "<<setw(8)<<head<<setw(8)<<abs(current_head - head)<<"\n";

        head=current_head;

    }
    cout<<"\nSeek time for FCFS is:"<<seek_time;

}
void SSTF(vector<int> q,int head1)
{
    vector<int> temp;
    vector<int> p;
    p=q;
    int head= head1;
    int len=p.size();
    int seek_time=0;
            cout<<"\n Next position"<<"             Head"<< "  Traversed tracks\n";

    while(len>0)
    {
        len--;
        for(auto current_head:p)
        {
            temp.push_back(abs(current_head - head));
        }

        int temp_time= *min_element(temp.begin(), temp.end());
        seek_time=seek_time+ *min_element(temp.begin(), temp.end());
        vector<int>::iterator itr = std::find(temp.begin(), temp.end(), temp_time);
        //distance(v.begin(), itr);
        cout<<"      "<<setw(10)<<p[distance(temp.begin(), itr)]<<"           "<<setw(8)<<head<<setw(8)<<temp_time<< "\n";

        head=p[distance(temp.begin(), itr)];
        auto it = p.begin()+distance(temp.begin(), itr);
        p.erase(it);
        temp.clear();

    }

    cout<<"\nSeek time for SSTF is:"<<seek_time;

}


void SCAN(vector<int>  p,int head ,string Direction )
{
        int disk_size=200;

    int temp =head;
    vector<int> left,right;
    int seek_time=0;
    string decide="null";
            cout<<"\n Next position"<<"             Head"<< "  Traversed tracks\n";

    for(auto i:p)
    {
        if(i<head) left.push_back(i);

    else
    {
        right.push_back(i);

    }
    }
sort(left.begin(),left.end());
reverse(left.begin(),left.end());
sort(right.begin(),right.end());

if(Direction=="left")
{
    for(auto i:left){
    seek_time=seek_time+ abs(temp-i);
        cout<<"      "<<setw(10)<<i<<"           "<<setw(8)<<temp<<setw(8)<<abs(temp-i)<< "\n";

        temp=i;

    }
    seek_time=seek_time+(temp-0);
        cout<<"      "<<setw(10)<<0<<"           "<<setw(8)<<temp<<setw(8)<<abs(temp-0)<< "\n";
    decide="right";
    temp=0;
}
else
    {
        cout<<"\n"
;     for(auto i:right){
    seek_time=seek_time+ abs(temp-i);
                   // cout<<"temp"<<temp<<" i "<<i<<"="<<abs(temp-i)<<"seek ="<<seek_time<<"\n";
        cout<<"      "<<setw(10)<<i<<"           "<<setw(8)<<temp<<setw(8)<<abs(temp-i)<< "\n";

    temp=i;

     }
         seek_time=seek_time+ abs(temp-(disk_size-1));

        decide="left";
    temp=disk_size-1;
        cout<<"      "<<setw(10)<<0<<"           "<<setw(8)<<temp<<setw(8)<<abs(temp-0)<< "\n";

}
if(decide=="left")
{
     for(auto i:left){
    seek_time=seek_time+ abs(temp-i);
                  // cout<<"temp"<<temp<<" i "<<i<<"="<<abs(temp-i)<<"seek ="<<seek_time<<"\n";
        cout<<"      "<<setw(10)<<i<<"           "<<setw(8)<<temp<<setw(8)<<abs(temp-i)<< "\n";

        temp=i;
     }
}
else
    {
        for(auto i:right){
    seek_time=seek_time+ abs(temp-i);
               // cout<<"temp"<<temp<<" i "<<i<<"="<<abs(temp-i)<<"seek ="<<seek_time<<"\n";
        cout<<"      "<<setw(10)<<i<<"           "<<setw(8)<<temp<<setw(8)<<abs(temp-i)<< "\n";

        temp=i;
        }


}

    cout<<"\nSeek time for SCAN is:"<<seek_time;

}
void CSCAN(vector<int> p,int head)
{
        int temp =head;
    int disk_size=200;
    vector<int> left,right;
    int seek_time=0;
    string decide="null";
            cout<<"\n Next position"<<"             Head"<< "  Traversed tracks\n";

    for(auto i:p)
    {
        if(i<head) left.push_back(i);

    else
    {
        right.push_back(i);

    }
    }
sort(left.begin(),left.end());
sort(right.begin(),right.end());
    for(auto i:right){
    seek_time=seek_time+ abs(temp-i);
               // cout<<"temp"<<temp<<" i "<<i<<"=" <<abs(temp-i)<<"seek ="<<seek_time<<"\n";
        cout<<"      "<<setw(10)<<i<<"           "<<setw(8)<<temp<<setw(8)<<abs(temp-i)<< "\n";

        temp=i;

    }
    seek_time=seek_time+abs(temp-(disk_size-1));
                //cout<<"temp"<<temp<<" i "<<disk_size-1<<"=" <<abs(temp-(disk_size-1))<<"seek ="<<seek_time<<"\n";
                            cout<<"      "<<setw(10)<<disk_size-1<<"           "<<setw(8)<<temp<<setw(8)<<abs(temp-0)<< "\n";

    seek_time=seek_time+disk_size-1;
    cout<<"      "<<setw(10)<<0<<"           "<<setw(8)<<disk_size-1<<setw(8)<<abs(disk_size-1-0)<< "\n";


    temp=0;

    for(auto i:left){
    seek_time=seek_time+ abs(temp-i);
               // cout<<"temp"<<temp<<" i "<<i<<"="<<abs(temp-i)<<"seek ="<<seek_time<<"\n";
        cout<<"      "<<setw(10)<<i<<"           "<<setw(8)<<temp<<setw(8)<<abs(temp-i)<< "\n";

        temp=i;
    }
        cout<<"\nSeek time for CSCAN is:"<<seek_time;

}
int main()
{
        cout.setf(ios:: left);

    vector< int> p= {176, 79, 34, 60, 92, 11, 41, 114};
    int head=50;
    FCFS(p,head);
    SSTF(p,head);
    SCAN(p,head,"left");
    CSCAN(p,head);
}
