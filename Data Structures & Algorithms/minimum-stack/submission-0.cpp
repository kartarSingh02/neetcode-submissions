class MinStack {
    struct StackNode {
        int val;
        int min;
    };
    vector<StackNode> data;

public:
    MinStack() {
    }
    
    void push(int val) {
        if (data.empty()) {
            StackNode new_node;
            new_node.val = val;
            new_node.min = val;
            data.push_back(new_node);

            return;
        }

        int current_min = data.back().min;
        StackNode new_node;

        if (val < current_min) {
            new_node.val = val;
            new_node.min = new_node.val;
            data.push_back(new_node);
        } else {
            new_node.val = val;
            new_node.min = data.back().min;
            data.push_back(new_node);
        }
    }

    void pop() {
        data.pop_back();
    }
    
    int top() {
        return data.back().val;
    }
    
    int getMin() {
        return data.back().min;
    }
};