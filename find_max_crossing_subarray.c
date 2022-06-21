typedef struct result
{
    int sum;
    int low;
    int high;
} Result;

Result find_max_crossing_subarray(int A[], int low, int mid, int high) // iterative
{
    Result result;
    int right_sum;
    int left_sum;

    int sum = 0;
    
    int max_right;
    int max_left;

    for (int i = mid; i >= low; i--)
    {
        sum = sum + A[i];
        if(sum > left_sum)
        {
            left_sum = sum;
            max_left = i;
        }
    }
    
    sum = 0;

    for (int j = mid+1; j <= high; j++)
    {
        sum = sum + A[j];
        if (sum > right_sum)
        {
            right_sum = sum;
            max_right = j;
        }
    }
    
    result.sum = left_sum + right_sum;
    result.low = max_left;
    result.high = max_right;

    return result;
}

Result find_maximum_subarray(int A[], int low, int high) //recursive
{
    Result result_left;
    Result result_right;
    Result result_cross;

    if(high == low)
    {
        Result result_default;
        result_default.high = high;
        result_default.low = low;
        result_default.sum = A[low];

        return result_default;
    }
    else
    {
        int mid = floor((low + high) / 2);

        //needed change 3 values by return
        result_left = find_maximum_subarray(A, low, mid);

        result_right = find_maximum_subarray(A, low, mid);

        result_cross = find_max_crossing_subarray(A, low, mid, high);

        if(result_left.sum >= result_right.sum && result_left.sum >= result_cross.sum)
            return result_left;
        else if(result_right.sum >= result_left.sum && result_right.sum >= result_cross.sum)
            return result_right;
        else
            return result_cross;
    }
}