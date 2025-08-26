/*
Interesting.
First thing that comes to mind is that we can build the vanilla list on a first
pass, setting random pointers as nullptr; One a second pass, we already have
every node, so we can point to them... But wait, how? Maybe, we could store each
node reference in a hash map. That would work. But traversing the list will not
allow us to take these jumps I'm thinking of. We don't have any explicit space
constraint. Anyway, if we're building a copy of that list, we're already on O(n)
space. Let's iterate a little bit on this hash map idea. For each node in the
original list we make map[node_ptr] = deep_copy_ptr That sounds very convenient.

Each node is represented as a pair of [val, random_index].
Ok, that makes things a little bit trickier.
There are no random pointers, just random indices.
We can easily solve that with an additional hash map where each key is the index
and the value is the node.

Input: head = [[1,1],[2,1]]
Output: [[1,1],[2,1]]

Maybe there's some esoteric inplace method. I like this hash map though.

*/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

// class Solution {
// public:
//     Node* copyRandomList(Node* head) {
//         std::unordered_map<Node*, Node*> copies;
//         std::unordered_map<int, Node*> idx_to_original_node;
//         Node* curr = head;
//         int idx = 0;
//         while (curr != nullptr) { // is this the best way to iterate?
//             copies[curr] = new Node(curr->val); // create deepcopy
//             idx_to_original_node[idx] = curr;   // index original node
//             curr = curr->next;                  // move forward
//             idx += 1;                           // increase idx
//         } // at this point we have stored every ref and created every copy, now
//           // we update the pointers
//         idx_to_original_node[idx] = nullptr;

//         int list_size = idx + 1;
//         curr = copies[head];
//         idx = 0;
//         while (curr != nullptr) {
//             if (idx + 1 == list_size) {
//                 curr->next == nullptr;
//             } else {
//                 Node* original_next_node = idx_to_original_node[idx + 1];
//                 Node* copied_next_node = copies[original_next_node];
//                 curr->next = copied_next_node;
//             }

//             Node* original_node = idx_to_original_node[idx];
//             Node* original_node_random = original_node->random;
//             Node* copied_node_random = copies[original_node_random];
//             curr->random = copied_node_random;

//             curr = curr->next;
//             idx += 1;
//         }
//         return copies[idx_to_original_node[0]];
//     }
// };

// very nice and clean recursive approach.
// class Solution {
// private:
//     std::unordered_map<Node*, Node*> copies;

// public:
//     Node* copyRandomList(Node* head) {
//         if (head == nullptr) {
//             return head;
//         }
        
//         if (this->copies.find(head) != this->copies.end()) {
//             return this->copies[head];
//         }

//         Node* node = new Node(head->val);
//         this->copies[head] = node;

//         node->next = this->copyRandomList(head->next);
//         node->random = this->copyRandomList(head->random);
//         return node;
//     }
// };

// interweaving, very elegant
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) {
            return head;
        }

        Node* curr = head;
        while (curr != nullptr) {
            Node* clone = new Node(curr->val);
            clone->next = curr->next;
            curr->next = clone;
            curr = clone->next;
        }
        curr = head;
        while (curr != nullptr) {
            if (curr->random != nullptr) {
                curr->next->random = curr->random->next;    // i don't understand this
            } else {
                curr->next->random = nullptr;
            }
            curr = curr->next->next;
        }

        Node* curr_old = head;                              // i also don't understand this very well
        Node* curr_new = head->next;
        Node* head_old = head->next;
        while (curr_old != nullptr) {
            curr_old->next = curr_old->next->next;
            if (curr_new->next != nullptr) {
                curr_new->next = curr_new->next->next;
            } 
            curr_old = curr_old->next;
            curr_new = curr_new->next;
        }
        return head_old;        
    }
};