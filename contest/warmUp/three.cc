#include<bits/stdc++.h>

int lengthLongestPath(std::string input) {
    std::stringstream ss;
    std::stack<std::string> directories;
    int ret = 0, tab_count=0,prev_tab_count = 0;
    bool prev_is_directry=false;
    for(auto it=input.begin();input.end()-it >=0;++it)
    {
        if(it==input.end() or *it=='\n')
        {
            //// pop appropriate values from the stack
            //// and retrieve the appropriae paret directoy string
            //// for this item
            std::stringstream new_dir;
            if(!directories.empty())
            {
                int i=prev_tab_count - tab_count +1;
                for(;i>0 and !directories.empty();--i)
                {
                    directories.pop();
                }
                //// taking account for the root directory
                if(!directories.empty())
                {
                    new_dir.str(directories.top());
                }
            }
            //// update stack and return value
            new_dir.str(new_dir.str()+ss.str()+'/');
            if(ss.str().find('.') !=-1)
            {
                ret=std::max(ret,(int)new_dir.str().length() - 1);
            }

            //// setup for the next item
            directories.push(new_dir.str());
            prev_tab_count = tab_count;
            tab_count = 0;
            ss.str("");
        }else if(*it == '\t')
        {
            ++tab_count;
        }
        else{
            ss<<*it;
        }
    }
    return ret;
}

int main()
{
    std::string s="dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext";
    std::string bigS="dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext";
    std::string EC="a";

    std::cout<<'\n'<<lengthLongestPath(s);
    std::cout<<'\n'<<lengthLongestPath(bigS);
    std::cout<<'\n'<<lengthLongestPath(EC);
}   