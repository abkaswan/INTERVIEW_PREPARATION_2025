import axios from "axios";
import { useEffect, useState } from "react";
import { Header } from "../../components/Header";
import "./OrdersPage.css";
import { OrdersGrid } from "./OrdersGrid";

export function OrdersPage({ cart, loadCart }) {
  const [orders, setOrders] = useState([]);

  useEffect(() => {
    const fetchOrders = async () => {
      const response = await axios.get("/api/orders?expand=products");
      setOrders(response.data);
    };
    fetchOrders();
  }, []);

  return (
    <>
      <title>Orders</title>
      <link rel="icon" type="image/svg+xml" href="images/orders-favicon.png" />

      <Header cart={cart} />

      <div className="orders-page">
        <div className="page-title">Your Orders</div>

        <OrdersGrid orders={orders} loadCart={loadCart} />
      </div>
    </>
  );
}
