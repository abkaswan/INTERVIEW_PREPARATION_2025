import {it, expect, describe, vi, beforeEach} from 'vitest';
import {render, screen, within} from '@testing-library/react';
import { MemoryRouter } from 'react-router';
import {HomePage} from './HomePage';
import axios from 'axios';

// now for homepage we use axios.get to fetch the products from backend so we need to mock that too
// now vi.mock('axios'); does nothing but we need it to return something , so we need to mock the impelementation => make the mock do whatever we want
vi.mock('axios');

describe('HomePage component',()=>{
    let loadCart;
    
    beforeEach(()=>{
        loadCart = vi.fn();

        axios.get.mockImplementation( async (urlPath)=>{
            if(urlPath === '/api/products'){
                return {
                    data : [{
                        id: "e43638ce-6aa0-4b85-b27f-e1d07eb678c6",
                        image: "images/products/athletic-cotton-socks-6-pairs.jpg",
                        name: "Black and Gray Athletic Cotton Socks - 6 Pairs",
                        rating: {
                        stars: 4.5,
                        count: 87
                        },
                        priceCents: 1090,
                        keywords: ["socks", "sports", "apparel"]
                    },
                    {
                        id: "15b6fc6f-327a-4ec4-896f-486349e85a3d",
                        image: "images/products/intermediate-composite-basketball.jpg",
                        name: "Intermediate Size Basketball",
                        rating: {
                        stars: 4,
                        count: 127
                        },
                        priceCents: 2095,
                        keywords: ["sports", "basketballs"]
                    },]
                }
            }
        });
    });


    it('displays the products corrrectly',async ()=>{
        render(
            <MemoryRouter>
                <HomePage cart = {[]} loadCart={loadCart}/>
            </MemoryRouter>
        );

        // find does the same thing as get but it will find it asynchronously and it returns a promise so we need to await it
        const productContainers = await screen.findAllByTestId('product-container');
        expect(productContainers.length).toBe(2);

        // within lets us find elements within a specific element
        expect(within(productContainers[0]).getByText('Black and Gray Athletic Cotton Socks - 6 Pairs')).toBeInTheDocument();
        expect(within(productContainers[1]).getByText('Intermediate Size Basketball')).toBeInTheDocument();

        // no need to check for image and rating stars image as they are already checked in product.test.jsx
        // for homepage component we focus on such as rendering multiple products and loading products using axios
    });
});