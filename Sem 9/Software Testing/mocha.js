function checkMaxPlusOneOfSorted(arr) {
    if (arr.length === 0)
        return undefined;

    for (let i = 0; i < arr.length - 1; i++) {
        if (arr[i] > arr[i + 1])
            return undefined
    }
    return arr[arr.length - 1] + 1;
}

var assert = require('assert');

describe('checkMaxPlusOneOfSorted', () => {

    it('should return undefined for unsorted array', () => {
        // Method Invocation
        const res = checkMaxPlusOneOfSorted([1, 2, 0]);
        // Assertions
        assert.equal(res, undefined);
    });

    it('should return undefined for empty array', () => {
        // Method Invocation
        const res = checkMaxPlusOneOfSorted([]);
        // Assertions
        assert.strictEqual(res, undefined);
    });

    it('should return max + 1 for sorted array', () => {
        // Method Invocation
        const res = checkMaxPlusOneOfSorted([1, 2, 3]);
        // Assertions
        assert.strictEqual(res, 4);
    });

    it('should return max + 1 for one elemnt', () => {
        // Method Invocation
        const res = checkMaxPlusOneOfSorted([1]);
        // Assertions
        assert.strictEqual(res, 2);
    });

});