#include <bits/stdc++.h>
#define repl(i,a,b) for(long long i = a; i < b; i++)
#define rep(i,a,b) for(int i = a; i < b; i++)
#define ll long long
#define pb push_back
typedef std::vector <int> vi;
typedef std::vector <long long> vll;
typedef std::vector <std::string> vs;
typedef std::vector <vi> vvi;
typedef std::vector <vll> vvl;
typedef std::vector <vs> vvs;
typedef std::pair <int, int> pi;
typedef std::pair <long long, long long> pll;
#define all(a) a.begin(),a.end()
#define debug(n) cout << #n << " : " << n << '\n'
#define debug2(n1,n2) cout << #n1 << " : " << n1 << "  " << #n2 << " : " << n2 << '\n'

#define MOD 1000000007

using namespace std;

#define MAX 10000001

bool isPrime[MAX]={0};
int storeValues[MAX] = {0};

void buildPrime(){
    for (int i=2;i<MAX;i++){
        if (!isPrime[i]){
            for (int j=(2*i);j<MAX;j+=i) isPrime[j]=1;
        }
    }
}

void buildStoreValues(){
    storeValues[5] = 2;
    for(int i=6;i<MAX;i++){
        storeValues[i] = storeValues[i-1];
        if (!isPrime[i] && !isPrime[i-2]) storeValues[i]++;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Use absolute paths for input and output files
    ifstream fin("C:\\Users\\kusha\\My_own_CSES_Solutions_and_DSA_Sol\\prime_subtractorization_input.txt");
    ofstream fout("C:\\Users\\kusha\\My_own_CSES_Solutions_and_DSA_Sol\\output.txt");

    // Check if files opened successfully
    if (!fin) {
        cerr << "Error opening input file!" << endl;
        return 1;
    }
    if (!fout) {
        cerr << "Error opening output file!" << endl;
        return 1;
    }

    // Test writing to output.txt
    // fout << "Test write to output file." << endl;
    fout.flush();  // Ensure output is flushed to the file immediately

    int Test, curr = 1;
    fin >> Test;
    buildPrime();
    buildStoreValues();

    // Loop to read input and write results
    while (curr <= Test) {
        int n;
        fin >> n;
        fout << "Case #" << curr << ": " << storeValues[n] << "\n";
        fout.flush();  // Flush the output after each case to ensure it's written
        curr++;
    }

    // Close the files
    fin.close();
    fout.close();

    return 0;
}
