
**algorithm**
        
        occurrences are keyword terminated sub-lists.
        
        occurrences are ordered by the right hand side terminator keyword
        
        the Search algorithm iterates forward over the words, complexity O(N):
        
```java
void Search::run() {
    for (int i=0; i < fileReader->get_words().size(); i++) {
        tmp = queue->push(fileReader->get_words()[i]);
        searchResults.reserve(searchResults.size() + tmp.size());
        searchResults.insert(searchResults.end(),
                             std::make_move_iterator(tmp.begin()),
                             std::make_move_iterator(tmp.end()));
    }
    cout << searchResults.size() << endl;
}
```

        
        occurrences, then, are collected in ForwardSearchFifoQueue::push, a fixed length FIFO queue:


```java
vector<pair<string, string>> ForwardSearchFifoQueue::push(string topItem) {
    vector<pair<string, string>> searchResults;
    queue1.pop_back();
    queue1.push_front(topItem);
    //if right item is a keyword
    if (keyword(topItem)) {
        for(int i=0; i< queue1.size(); i++) {
            //if left item is the other keyword
            if (otherKeyWord(queue1[i], topItem)) {
                searchResults.push_back((make_pair(queue1[i],topItem)));
            }
        }
    }
    return searchResults;
}
```



**build**
        
        standard cmake build, see CMakeLists.txt

**tests**
        
        main the canal 6 input.txt
        
        3
        
        main the canal 3 input.txt
        
        1
        
        main a b 13 example.txt
        
        19
        
        main a b 3 example.txt
        
        1
        
        main  c b 3 example.txt
        
        3
        
        main  c b 13 example.txt
        
        15
        
        main  cc b 13 example.txt
        
        0
        
        main  ccc b 13 example.txt
        
        10

