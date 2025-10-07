import {it, expect, describe} from 'vitest';
import {formatMoney} from './money';

// grouping related tests , describe = groups tests together , group of tests => test suite , test suite let's us basically keep our test more organized
describe('formatMoney',()=>{
    // describing the test -- naming conventinon read it like english
    it('formats 1999 cents as $19.99',()=>{
       expect(formatMoney(1999)).toBe('$19.99');
    });
    
    // can have multiple checks also in one test
    it('displays 2 decimals',()=>{
        expect(formatMoney(1090)).toBe('$10.90');
        expect(formatMoney(100)).toBe('$1.00');
    })
});

