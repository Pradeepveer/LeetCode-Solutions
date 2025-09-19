#include<bits/stdc++.h>
using namespace std;

// Find all friendship pairs that do not share any language.
// Collect all users in these pairs who need to learn a language.
// For each possible language l from 1 to n, count how many of these users do not know language l.
// Return the minimal such count.


class Solution {
public:
    bool checkcommon(vector<vector<int>>& languages, int u, int v){
        set<int> st;
        for (int i=0; i<languages[u-1].size(); i++){
            st.insert(languages[u-1][i]);
        }

        for (int i=0; i<languages[v-1].size(); i++){
            if (count(st.begin(), st.end(), languages[v-1][i]) > 0) return true;
        }

        return false;
    }

    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        set<int> no_common;

        // Collect all users in these pairs who need to learn a language
        for (int i=0; i<friendships.size(); i++){
            if (!checkcommon(languages, friendships[i-1][0], friendships[i-1][1])){
                no_common.insert(friendships[i][0]);
                no_common.insert(friendships[i][1]);
            }
        }

        // For each possible language l from 1 to n, count how many of these users do not know language l
        int maxi = 0;
        unordered_map<int, int> mp; // < language, no of user in no_commmon that know the language>
        for (auto it : no_common){
            for (int j=0; j<languages[it-1].size(); j++){
                int lang = languages[it-1][j];
                mp[lang]++;
                maxi = max(maxi, mp[lang]);
            }
        }

        return no_common.size() - maxi;
    }
};


// faster solution
class Solution {
public:
     int minimumTeachings(int totalLanguages, vector<vector<int>>& userLanguages, vector<vector<int>>& friendships) {
        unordered_set<int> usersToTeach;

        // Step 1: Identify users who can't communicate
        for (auto& friendship : friendships) {
            int user1 = friendship[0] - 1; // Convert to 0-based index
            int user2 = friendship[1] - 1;
            bool canCommunicate = false;

            for (int lang1 : userLanguages[user1]) {
                for (int lang2 : userLanguages[user2]) {
                    if (lang1 == lang2) {
                        canCommunicate = true;
                        break;
                    }
                }
                if (canCommunicate) break;
            }

            if (!canCommunicate) {
                usersToTeach.insert(user1);
                usersToTeach.insert(user2);
            }
        }

        // Step 2: Try teaching each language
        int minUsersToTeach = userLanguages.size() + 1;

        for (int language = 1; language <= totalLanguages; language++) {
            int count = 0;

            for (int user : usersToTeach) {
                bool knowsLanguage = false;
                for (int lang : userLanguages[user]) {
                    if (lang == language) {
                        knowsLanguage = true;
                        break;
                    }
                }
                if (!knowsLanguage) count++;
            }

            minUsersToTeach = min(minUsersToTeach, count);
        }

        return minUsersToTeach;
    }
};