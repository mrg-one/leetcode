function isPossibleToRearrange(s: string, t: string, k: number): boolean {

    const substrings = new Map<string, number>();

    const targetSubstrings = new Map<string, number>();

    const subStringSize = (t.length / k)

    for (let i = 0; i < k; i++)
        targetSubstrings.set(t.substring(i * subStringSize, (i + 1) * subStringSize), (targetSubstrings.get(t.substring(i * subStringSize, (i + 1) * subStringSize)) || 0) + 1);

    for (let i = 0; i < k; i++)
        substrings.set(s.substring(i * subStringSize, (i + 1) * subStringSize), (substrings.get(s.substring(i * subStringSize, (i + 1) * subStringSize)) || 0) + 1);
    
    for (const [substring, count] of substrings)
        if ((targetSubstrings.get(substring) || 0) < count)
            return false;
    
    return true
};

console.log(isPossibleToRearrange("dawdawwadwad", "waddawdawdaw", 4));