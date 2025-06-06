// 🧠 Summary
// Step	Purpose
// 1️⃣	Create a set of all destination cities
// 2️⃣	Find the source city that is not a destination
// 3️⃣	Follow the route using the map and print it step-by-step
#include<bits/stdc++.h>
using namespace std;

void printItinerary(unordered_map<string,string> tickets){

    // 1. find the starting point
    unordered_set<string> to ;

    for(pair<string,string> ticket : tickets)//from , to
    {
        to.insert(ticket.second);
    }

    string start ="";

    for(pair<string,string> ticket : tickets)
    {
        if(to.find(ticket.first) ==  to.end())
        {
            start = ticket.first;
        }
    }

    // plam print
    cout<<start<<"->";
    while(tickets.count(start))
    {
        cout<<tickets[start]<<"->";
        start=tickets[start];
    }
    cout<<"destination->"<<endl;

}

int main(){
    unordered_map<string,string> tickets;
    tickets["Chennai"] = "Bengaluru";
    tickets["Mumbai"] = "Delhi";
    tickets["Goa"] = "Chennai";
    tickets["Delhi"] = "Goa";
    printItinerary(tickets);
    return 0;
}