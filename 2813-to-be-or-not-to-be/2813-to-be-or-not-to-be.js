/**
 * @param {any} val
 * @return {Object}
 */
var expect = function(val) {
    return {
        toBe: function(other) {
            if (val === other) {
                return true;
            } else {
                throw new Error("Not Equal");
            }
        },
        notToBe: function(other) {
            if (val !== other) {
                return true;
            } else {
                throw new Error("Equal");
            }
        }
    };
};

/**
 * expect(5).toBe(5); // ✅ true
 * expect(5).notToBe(5); // ❌ throws "Equal"
 * expect('10').toBe(10); // ❌ throws "Not Equal"
 * expect('10').notToBe(10); // ✅ true
 */
