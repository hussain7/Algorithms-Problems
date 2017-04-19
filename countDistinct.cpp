void countDistinct(int A[], int k, int n)
{
    //Your code here
    // count frst time
    
    std::map<int, int> countMap;
    for(int i=0;i<k; i++)
    {
        countMap[A[i]]++;
    }
    
    // get intil number 
    std::vector<int> output;
    output.push_back(countMap.size());
    
    // move window now
    for(int i=1; i<n-k+1; i++)
    {
        // handle new number
        countMap[A[i+k-1]]++;
        
        // delete previous number
        countMap[A[i-1]]--;
        if(countMap[A[i-1]] ==0 ) 
            countMap.erase(A[i-1]);
            
        output.push_back(countMap.size());
            
    }
    
    // print output
    for(auto itr=output.begin(); itr != output.end(); itr++)
    {
        
        std::cout<<*itr;
    }
}
