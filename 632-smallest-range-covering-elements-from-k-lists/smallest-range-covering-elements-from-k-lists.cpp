class Node{
    public:
        int data;
        int row;
        int col;
        
    Node(int data, int row, int col){
        this -> data = data;
        this -> row = row;
        this -> col = col;
    }
};

class compare{
    public:
        bool operator()(Node* a, Node* b){
            return a -> data > b -> data;
        }
};

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int n = nums.size();
        int mini = INT_MAX;
        int maxi = INT_MIN;

        priority_queue<Node*, vector<Node*>, compare> pq;

        for(int i = 0; i < n; i++){
            Node* temp = new Node(nums[i][0], i, 0);
            mini = min(mini, temp -> data);
            maxi = max(maxi, temp -> data);
            pq.push(temp);
        }

        int start = mini, end = maxi;

        while(!pq.empty()){
            Node* top = pq.top();
            pq.pop();

            mini = top -> data;

            if(maxi - mini < end - start){
                start = mini;
                end = maxi;
            }

            if(top -> col + 1 < nums[top->row].size()){
                maxi = max(maxi, nums[top -> row][top -> col + 1]);
                Node* newNode = new Node(nums[top -> row][top -> col + 1], top -> row, top->col+1);
                pq.push(newNode);
            }else{
                break;
            }
        }

        return {start, end};
    }
};