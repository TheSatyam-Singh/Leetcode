// Last updated: 20/07/2026, 10:52:31
/**
 * @return {null|boolean|number|string|Array|Object}
 */
Array.prototype.last = function() {
    if (this.length===0){
        return -1;
    }
    return this[this.length-1];  
};

/**
 * const arr = [1, 2, 3];
 * arr.last(); // 3
 */