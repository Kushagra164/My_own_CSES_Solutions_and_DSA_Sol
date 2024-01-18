#include <bits/stdc++.h>
#define rep(i,a,b) for(int i = a; i < b; i++)
#define ll long long
#define pb push_back
#define all(a) a.begin(),a.end()
#define MOD 1000000007

using namespace std;

//Code By Kush
/*
    Input Format:
    n
    arr....
*/ 
// Assuming a valid input i.e., n>0 and 

/*
    Output Format:
    Sorted List with duplicates
    Sorted List with no duplicates
    k-reversed List
*/

class LinkedList{
    public:
        int val;
        LinkedList* next;

        LinkedList(int val){
            this->val=val;
            this->next = NULL;
        }
};


// Utility functions
void printLinkedList(LinkedList* head){
    LinkedList* dummyHead = head;
    while(dummyHead!=NULL){
        cout << dummyHead->val << " ";
        dummyHead = dummyHead->next;
    }
    cout << "\n";
}

int lengthOfLinkedList(LinkedList* head) {
    int length = 0;
    LinkedList* dummyHead = head;
    while(dummyHead != NULL) {
        ++length;
        dummyHead = dummyHead->next;
    }
    return length;
}

void ReverseLinkedList(LinkedList* pre,LinkedList* cur,LinkedList* nex,int k){
    for(int i=1;i<k;i++) {
        cur->next = nex->next;
        nex->next = pre->next;
        pre->next = nex;
        nex = cur->next;
    }
}

// Main functions
LinkedList* insertInNonDecreasingOrder(vector<int> arr,int n){
    sort(arr.begin(),arr.end());
    LinkedList* head = new LinkedList(arr[0]);
    LinkedList* dummyHead=head;
    for (int i=1;i<n;i++){
        LinkedList* newNode = new LinkedList(arr[i]);
        dummyHead->next = newNode;
        dummyHead = newNode; 
    }
    return head;
}

LinkedList* RemoveDuplicates(LinkedList* head){
    LinkedList* dummyHead = head;
    while(dummyHead->next != NULL){
        LinkedList* nex = dummyHead->next;
        if (nex->val == dummyHead->val){
            dummyHead->next = nex->next;
            delete nex;
        }
        else{
            dummyHead = nex;
        }
    }
    return head;
}

LinkedList* ReverseKNodes(LinkedList* head,int k){
    if(head == NULL||head->next == NULL) return head;
    
    int length = lengthOfLinkedList(head);
    
    LinkedList* dummyHead = new LinkedList(0);
    dummyHead->next = head;
    
    LinkedList* pre = dummyHead;
    LinkedList* cur;
    LinkedList* nex;
    
    while(length >= k) {
        cur = pre->next;
        nex = cur->next;
        ReverseLinkedList(pre,cur,nex,k);
        pre = cur;
        length -= k;
        if (length == 0 || length == 1) break;
        if (length<k){
            cur = pre->next;
            nex = cur->next;
            ReverseLinkedList(pre,cur,nex,length);
            pre = cur;
            break;
        }
    }


    return dummyHead->next;
}

void solve() {
    int n,k;
    cin >> n;
    vector<int> arr(n);
    rep(i,0,n) {
        cin >> arr[i];
    }
    cin >> k;

    LinkedList* head = insertInNonDecreasingOrder(arr,n);
    cout << "Sorted List with duplicates: ";
    printLinkedList(head);
    
    head = RemoveDuplicates(head);
    cout << "Sorted List with no duplicates: ";
    printLinkedList(head);
    
    head = ReverseKNodes(head,k);
    cout << k << "-Reversed List: ";
    printLinkedList(head);

    return ;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // cout << "thik hai";
    solve();
    return 0;
}