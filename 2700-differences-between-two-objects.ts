type JSONValue = null | boolean | number | string | JSONValue[] | { [key: string]: JSONValue };
type Obj = Record<string, JSONValue> | Array<JSONValue>;

function objDiff(a: Obj, b: Obj): Obj {
    if (Array.isArray(a) !== Array.isArray(b)) {
        return [a, b];
    }

    const result = {};

    for (const [key, value] of Object.entries(a)) {
        if (!b.hasOwnProperty(key)) {
            continue;
        }

        if (value !== null && typeof value == 'object') {
            const diff = objDiff(value, b[key]);
            if (Object.keys(diff).length !== 0) {
                result[key] = diff;
            }
        } else {
            if (value !== b[key]) {
                result[key] = [value, b[key]];
            }
        }
    }

    return result;
};
