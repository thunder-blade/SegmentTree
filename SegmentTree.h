#include <functional>

template<class T>
class SegmentTree {

    public:
    	T compose(T arg1, T arg2){
    		//.......
    	}

    private:
        class SegNode {
            public:
                T value;
                int seg_start, seg_end;
                SegNode* left;
                SegNode* right;
                SegNode (T value, int seg_start, int seg_end, SegNode* left=0, SegNode* right=0) {
                    this->value = value;
                    this->seg_start = seg_start;
                    this->seg_end = seg_end;
                    this->left = left;
                    this->right = right;
                }
        };

        T composeUtil (T arg1, T arg2) {
           return f(arg1, arg2);
        }

        // Creating the Segment Tree.
        SegNode* createST(T leaves[], int start, int end) {
            // base case - leaf of tree.
            if (start==end)
                return new SegNode(leaves[start],start,start,0,0);
            // general case.
            int mid = start + (end-start)/2;
            SegNode* left = createST(leaves,start,mid);
            SegNode* right = createST(leaves,mid+1,end);
            T retValue = composeUtil(left->value,right->value);
            return new SegNode(retValue,start,end,left,right);
        }

        // Range Query helper.
        T queryUtil (SegNode* root, int start, int end) {
            int seg_start = root->seg_start, seg_end = root->seg_end;
            /*if (seg_start>end || seg_end<start)
                return 0;*/
            if (seg_start>=start && seg_end<=end)
                return root->value;
            else{
                if(root->left->seg_start>end || root->left->seg_end<start)
                    return queryUtil(root->right,start,end);
                if(root->right->seg_start>end || root->right->seg_end<start)
                    return queryUtil(root->left,start,end);
                return f(queryUtil(root->left,start,end),queryUtil(root->right,start,end));
            }
        }

        // Helper function for Updating the Segment Tree.
        void updateUtil (SegNode* root, int position, T updatedValue) {
            int seg_start = root->seg_start, seg_end = root->seg_end;
            if(seg_start>position || seg_end<position)
                return;
            if(seg_start==seg_end && seg_start==position){
                root->value = updatedValue;
                return;
            }
            updateUtil(root->left, position, updatedValue);
            updateUtil(root->right, position, updatedValue);
            root->value = composeUtil(root->left->value,root->right->value);
        }

        // Freeing the memory allocated to the Segment Tree.
        void destroyTree(SegNode* root) {
            if (root->left!=0)
                destroyTree(root->left);
            if (root->right!=0)
                destroyTree(root->right);
            delete root;
        }

        SegNode* root;
        T (*f)(T, T) = compose;

    public:
        SegmentTree (T leaves[], T (*compose)(T,T), int start, int end) {
            this->f = compose;
            this->root = createST(leaves, start, end);
        }

        T query (int start, int end) {
            return queryUtil(root, start, end);
        }

        void update (int position, T updatedValue) {
            updateUtil(root, position, updatedValue);
        }

        ~SegmentTree () {
            destroyTree(root);
        }
};