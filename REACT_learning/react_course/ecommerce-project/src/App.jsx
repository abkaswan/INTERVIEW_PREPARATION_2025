import {useEffect,useState} from 'react';
import axios from 'axios';
import { Route, Routes } from 'react-router';
import { HomePage } from './pages/home/HomePage';
import { CheckoutPage } from './pages/checkout/CheckoutPage';
import { OrdersPage } from './pages/orders/OrdersPage';
import { TrackingPage } from './pages/TrackingPage';
import { NotFoundPage } from './pages/NotFoundPage';
import './App.css'

function App() {
  // lift the state up from homePage to app because we need it in homepage and checkoutpage both
  const [cart, setCart] = useState([]);
  
  useEffect(() => {
    const fetchAppData = async () => {
      const response = await axios.get('/api/cart-items?expand=product');
      setCart(response.data);
    }

    fetchAppData();
  }, []);

  return (
    <Routes>
      <Route index element={<HomePage cart = {cart}/>} />
      <Route path="checkout" element={<CheckoutPage cart={cart}/>} />
      <Route path="orders" element={<OrdersPage cart={cart}/>} />
      <Route path="tracking" element={<TrackingPage cart={cart}/>} />
      <Route path="*" element={<NotFoundPage />} />
    </Routes>
  )
}

export default App
