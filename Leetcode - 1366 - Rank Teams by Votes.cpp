class Solution {
public:
    struct State {
        char team_name; 
        int amount_vote; 

        State(char team_name, int amount_vote): team_name(team_name), amount_vote(amount_vote) {}

        bool operator<(const State& other) const {
            return amount_vote < other.amount_vote;
        }
    };
    
    const static int MAX_ALPHABETS = 26; 
    
    string rankSplit(vector<char> teams, vector<string>& votes, int position) {
        int count[MAX_ALPHABETS];
        priority_queue<State, vector<State>, less<State>> pq;
        if (position == votes[0].size() || teams.size() == 1) {
            string answer = "";
            sort(teams.begin(), teams.end());
            for (auto team : teams) {
                answer = answer + team;
            }
            return answer;
        }

        for (char team : teams) {
            count[team - 'A'] = 0;
        }

        for (string vote : votes) {
            count[vote[position] - 'A'] += 1;
        }

        for (char team : teams) {
            pq.push(State(team, count[team - 'A']));
        }

        string answer = "";
        vector<char> list_team; 
        while (pq.empty() == false) {
            State currentState = pq.top(); pq.pop(); 
            char team = currentState.team_name;
            int amount_vote = currentState.amount_vote;
            if (list_team.empty() || amount_vote == count[list_team[0] - 'A']) {
                list_team.push_back(team);
            } else {
                answer = answer + rankSplit(list_team, votes, position + 1);
                list_team.clear();
                list_team.push_back(team);
            }
        }
        if (list_team.empty() == false) {
            answer = answer + rankSplit(list_team, votes, position + 1);
            list_team.clear();
        }
        return answer; 
    }
    string rankTeams(vector<string>& votes) {
        vector<char> list_team;
        for (auto team : votes[0]) {
            list_team.push_back(team);
        }
        return rankSplit(list_team, votes, 0);
    }
};
