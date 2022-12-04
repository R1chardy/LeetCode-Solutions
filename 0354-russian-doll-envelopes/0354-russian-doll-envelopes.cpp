class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes)
{
    // Sort the array of envelopes in ascending order by width,
    // and in descending order by height
    sort(envelopes.begin(), envelopes.end(), [](const vector<int>& a, const vector<int>& b)
    {
        if (a[0] == b[0])
        {
            return a[1] > b[1];
        }
        return a[0] < b[0];
    });

    // Create an empty vector to store the heights of the envelopes
    vector<int> h;

    // Iterate over the envelopes and add their heights to h using a binary search
    for (const vector<int>& envelope : envelopes)
    {
        // Use binary search to find the correct position for the current envelope height
        auto it = lower_bound(h.begin(), h.end(), envelope[1]);

        // If the current envelope height is not already in h, add it
        if (it == h.end())
        {
            h.push_back(envelope[1]);
        }
        // Otherwise, replace the current envelope height with the new one
        else
        {
            *it = envelope[1];
        }
    }

    // Return the length of h
    return h.size();
}

};