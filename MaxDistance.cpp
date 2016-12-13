
int maxDistance(int arr[], int n)
{
//Code here
std::map<int, std::pair<int, long int>> distanceMap;

long int sum=0;
for(int i=0; i<n ; i++)
{
    if(distanceMap.find(arr[i]) != distanceMap.end())
    {
        auto itr = distanceMap.find(arr[i]);
        itr->second.second += i - itr->second.first; 
        itr->second.first = i;
        if(itr->second.second >  sum) 
            sum = itr->second.second ;
    }
    else
    {
        distanceMap[arr[i]] = std::make_pair(i, 0);
    }
}

    return sum;
}
