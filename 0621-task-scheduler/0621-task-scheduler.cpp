class Character
{
    public:
        char name;
    int cooldown;
    int totalCharacter;

   	// Constructor
    Character(char n, int ic, int tc): name(n), cooldown(ic), totalCharacter(tc) {}

   	// Overload operator < for priority queue
    bool operator < (const Character &other) const
    {
       	// Higher intervalCooldown has higher priority
        return cooldown > other.cooldown;
    }
};

class Solution
{
    public:
        int leastInterval(vector<char> &tasks, int n)
        {
            vector<int> vi(26, 0);
            
            for(auto data : tasks){
                vi[data - 'A']++;
            }
            
            priority_queue<Character> pq;
            
            for(int i = 0; i < 26; i++){
                if(vi[i] > 0){
                    Character c(i + 'A', 0, vi[i]);
                    pq.push(c);
                }
            }
            
            int countCooldown = 0;
            
            while(true){
                bool done = true;
                
                while(pq.empty() == false){
                    Character c = pq.top();
                    pq.pop();
                    
                    if(c.cooldown <= countCooldown){
                        c.cooldown += (n + 1);
                        c.totalCharacter -= 1;
                    }
                    
                    if(c.totalCharacter > 0) {
                        pq.push(c);
                        done = false;
                    }
                    countCooldown++;
                }
                
                if(done) break;
            }
            
            return countCooldown;
        }
};











