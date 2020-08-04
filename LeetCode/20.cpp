class Solution {
public:
    bool isValid(string s) {
        stack<char> s_;
        for(auto i : s)
            if(i == '(' || i == '{' || i == '[')
                s_.push(i);
            else if(!s_.empty())
                switch(i)
                {
                    case ')':
                        if(s_.top() != '(')
                            return false;
                        s_.pop();
                        break;
                    case '}':
                        if(s_.top() != '{')
                            return false;
                        s_.pop();
                        break;
                    case ']':
                        if(s_.top() != '[')
                            return false;
                        s_.pop();
                        break;
                }
            else
                return false;
        return s_.empty();
    }
};