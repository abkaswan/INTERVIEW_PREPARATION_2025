import axios from 'axios';
import {useEffect, useState} from 'react';
import { useSearchParams } from 'react-router';
import { Header } from "../../components/Header";
import "./HomePage.css";
import { ProductsGrid } from './ProductsGrid';

export function HomePage({cart, loadCart}) {
  // to fetch data from backend - we need to use useState to store the data
  const [products, setProducts] = useState([]);
  const [searchParams] = useSearchParams();
  const search = searchParams.get("search");
  // need to use useEffect to fetch data from backend - so that it only runs once when the component mounts
  useEffect(() => {
    const getHomeData = async () => {
      const urlPath = search ? `/api/products?search=${search}` : '/api/products';
      const response = await axios.get(urlPath);
      setProducts(response.data);
    };
    
    getHomeData();
  }, [search]);
  
  return (
    <>
      <title>Ecommerce Project</title>
      <link rel="icon" type="image/svg+xml" href="images/home-favicon.png" />

      <Header cart={cart} />

      <div className="home-page">
        <ProductsGrid products={products} loadCart={loadCart} />
      </div>
    </>
  );
}
