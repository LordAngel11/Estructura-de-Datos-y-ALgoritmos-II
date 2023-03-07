



int intersection(int vertice, int left_t, int right_t, int left, int right){
            if(left_t<=left && right<=right_t && tree[vertice]>0){
                return abs(right-left) + 1;
            }
            if(right<left || right<left_t || right_t<left){
                return 0;
            }else if(left_t==left && right_t==right){
                return lazy[vertice];
            }else{
                int t = (left_t+right_t)/2;
                if(tree[vertice] > 0)
                    return max(abs(min(right_t,right)-max(left_t,left))+1,intersection(2*vertice+1,left_t,t,left,min(right,t)) + 
                    intersection(2*vertice+2,t+1,right_t,max(left,t+1),right));    
                else
                    return intersection(2*vertice+1,left_t,t,left,min(right,t)) + intersection(2*vertice+2,t+1,right_t,max(left,t+1),right);
            }
        }