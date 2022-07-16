#include<stack>
bool findRedundantBrackets(string &s)
{
    stack<char> st;
    for(int i = 0; i<s.length(); i++){
        char ch = s[i];
        
        if(ch== '(' || ch=='+' || ch=='-' || ch=='/' || ch=='*'){
            st.push(ch);
        }
        else{
            //closing bracket or lower case value	=> ignore lower case values we need only closing tag se dekhenge
            if(ch==')'){
                bool isRedundant = true;
                //check operator hai ki nhi, jab tak ek opening bracket na mil jaye
                while(st.top()!='('){	//opening bracket
                    char top = st.top();
                    if(top=='+' || top=='-' || top=='/' || top=='*'){
                        //operator hai
                        isRedundant = false;
                    }
                    //remove that element
                    st.pop();
                }	//is loop se tab bahar jab ek opening bracket mila hoga
                if(isRedundant == true){
                    return true;
                }
                st.pop();	//remove that opening bracket encountered as exited loop
            }
        }
    }//for end overall out
    return false;	//if it was redundant we have returned already, now we will return false
}