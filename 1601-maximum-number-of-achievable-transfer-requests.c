int helper(
    int** requests, 
    int   size,
    int*  degrees,
    int   n,
    int   result
) {
    if (size == 0) {
        for (int i = 0; i < n; i++)
            if (degrees[i] != 0)
                return 0;
        return result;
    }

    int* request     = requests[0];
    int  not_granted = helper(
        requests + 1, 
        size - 1, 
        degrees, 
        n, 
        result
    );

    degrees[request[0]]--;
    degrees[request[1]]++;

    int granted = helper(
        requests + 1, 
        size - 1, 
        degrees, 
        n, 
        result + 1
    );

    degrees[request[0]]++;
    degrees[request[1]]--;

    return granted > not_granted ? granted : not_granted;
}


int maximumRequests(
    int   n, 
    int** requests, 
    int   size, 
    int*  unused
){
    int* degrees = calloc(n, sizeof(int));
    int result   = helper(requests, size, degrees, n, 0);
    free(degrees);
    return result;
}
