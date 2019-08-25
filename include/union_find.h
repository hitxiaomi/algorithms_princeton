//
// Created by xiaomi on 8/25/19.
//

#ifndef ALGORITHMS_PRINCETON_UNION_FIND_H
#define ALGORITHMS_PRINCETON_UNION_FIND_H
#include <vector>


namespace  algorithms_princeton
{
    class UnionFind{
    public:
        explicit UnionFind(int n){
            if(n<0)
                throw "IllegalArgumentException";
            count_=n;
            parent_.resize(n);
            rank_.resize(n,0);
            for(int i=0;i<n;i++){
                parent_[i]=i;
            }


        }

        int Find(int p){
            while(p!=parent_[p]){
                parent_[p]=parent_[parent_[p]]; //path compression
                p=parent_[p];
            }
            return p;


        }
        void Union(int p,int q){
            int root_p=Find(p);
            int root_q=Find(q);
            if(root_p==root_q)
                return;
            if(rank_[root_p]<rank_[root_q])
                parent_[root_p]=root_q;  //rank not change
            else if(rank_[root_p]>rank_[root_q])
                parent_[root_q]=root_p;
            else{
                parent_[root_q]=root_p;
                rank_[root_p]++; //rank increase
            }
            count_--;
        }

        bool  Connected(int p,int q)  {
            return Find(p)==Find(q);

        }
        int Count() const {
            return count_;

        }

    private:
        std::vector<int> parent_;
        std::vector<int > rank_;
        int count_;

    };

}

#endif //ALGORITHMS_PRINCETON_UNION_FIND_H
