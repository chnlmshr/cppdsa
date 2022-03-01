#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    string s;
    cin >> s;
    unordered_map<char, int> hash;
    for (int i = 0; i < n; i++)
    {
      hash[s[i]]++;
    }
    if (n & 1)
    {
      cout << "NO";
    }
    else
    {
      bool flag = 1;
      for (int i = 0; i < n / 2; i++)
      {
        if (s[i] == s[n - i - 1])
        {
          flag = 0;
          break;
        }
      }
      if (flag == 1)
      {
        cout << "YES" << endl;
        cout << s;
      }
      else
      {
        flag = 0;
        for (auto x : hash)
        {
          if (x.second > n / 2)
          {
            flag = 1;
            break;
          }
        }
        if (flag == 1)
        {
          cout << "NO";
        }
        else
        {
          cout << "YES" << endl;
          sort(s.begin(), s.end());
          int j = n / 2;
          int i = 0;
          j--;
          while (i < j)
          {
            swap(s[i], s[j]);
            i++;
            j--;
          }
          cout << s;
        }
      }
    }
    cout << "\n";
  }
  return 0;
}

// #include <bits/stdc++.h>

// using namespace std;

// int main() {

//   ios_base ::sync_with_stdio(false);
//   cin.tie(nullptr);
//   cout.tie(nullptr);

//   int t; cin >> t;
//   while(t--) {
//     int n; cin >> n;
//     string s; cin >> s;
//     if(n & 1) cout << "NO";
//     else {
//       vector<pair<int, int>> freq(26); // a = 97
//       for(int i = 0; i < 26; i++) {
//         freq[i].first = 0;
//         freq[i].second = i;
//       }
//       for(char c : s) {
//         freq[c - 97].first++;
//       }
//       sort(freq.begin(), freq.end(), greater<pair<int, int>>());
//       if(freq[0].first > n/2) cout << "NO";
//       else {
//         cout << "YES\n";
//         for(int i = 0; i < 26; i++) {
//           while(freq[i].first) {
//             cout << (char)(freq[i].second + 97);
//             freq[i].first--;
//           }
//         }
//       }
//     }
//     cout << "\n";
//   }

//   return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;

// int main() {
// 	// your code goes here
// 	ios_base::sync_with_stdio(0);
// 	cin.tie(0);
// 	int t;
// 	cin>>t;
// 	while(t--)
// 	{
// 	   int n;
// 	   cin>>n;
// 	   string s;
// 	   cin>>s;
//      unordered_map<char,int> mp;
//      for(int i=0;i<n;i++)
//      {
//          mp[s[i]]++;
//      }
// 	   if(n%2!=0)
// 	   {
// 	       cout<<"NO"<<endl;
// 	   }
// 	   else
// 	   {
// 	       bool f=1;
// 	       for(int i=0;i<n/2;i++)
// 	       {
// 	           if(s[i]==s[n-i-1])
// 	           {
// 	               f=0;
// 	               break;
// 	           }
// 	       }
// 	       if(f==1)
// 	       {
// 	           cout<<"YES"<<endl;
// 	           cout<<s<<endl;
// 	       }
// 	       else
// 	       {
// 	           f=0;
// 	           for(auto x:mp)
// 	           {
// 	               if(x.second>n/2)
// 	               {
// 	                   f=1;
// 	                   break;
// 	               }
// 	           }
// 	           if(f==1)
// 	           {
// 	               cout<<"NO"<<endl;
// 	           }
// 	           else
// 	           {
// 	               cout<<"YES"<<endl;
// 	               sort(s.begin(),s.end());
// 	               int j=n/2;
// 	               int i=0;
// 	               j--;
// 	               while(i<j)
// 	               {
// 	                   swap(s[i],s[j]);
// 	                   i++;
// 	                   j--;
// 	               }

//         	           cout<<s<<endl;
//         	       }

// 	           }
// 	       }
// 	}
// 	return 0;
// }
