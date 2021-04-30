/*Given a singly linked list, write code to find the most frequent element value in the list and its occurrence.
In case of duplicate number of occurrences, return the element value closest to the head.
A solution of time complexity O(N) average is preferred.

Sample Input: 1 2 3 4 2 3 2
Sample Output: Element 2 occurs 3 time(s)

Sample Input: 4 3 5 3 4 5
Sample Output: Element 4 occurs 2 time(s)*/

/* with out the duplicate bit*/
pair<int, int> findMostFrequentElement(LinkedListNode* node)
{
    pair<int, int> result;
    unordered_map<int,int> frequency;
    int max=0;
    int max_key=0;
    int key;

    
    while(node!=NULL){
        

        frequency[node->value]++;
                
        if (frequency[node->value]>max){
            max_key=node->value;
            max=frequency[node->value];
            cout<<"Max is:"<< max<< " key is:" << max_key<<endl;
            result=make_pair(max_key,max);
            
        }      
        node=node->next;
        
        
        
    }
	return result;