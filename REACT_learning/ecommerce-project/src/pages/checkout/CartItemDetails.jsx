import { useState } from "react";
import { formatMoney } from "../../utils/money";
import axios from "axios";

export function CartItemDetails({ cartItem , deleteCartItem, loadCart}) {
  const [isQuantityUpdated, setIsQuantityUpdated] = useState(false);
  const [quantity, setQuantity] = useState(cartItem.quantity);

  const handleUpdateQuantity = async () => {
    // when clicking udpate switch this state between true and false, if state is true show the textbox otherwise show quantity label
    if(isQuantityUpdated){
      await axios.put(`/api/cart-items/${cartItem.productId}`, {
        quantity: Number(quantity),
      });
      await loadCart();

      setIsQuantityUpdated(false);
    }
    else{
      setIsQuantityUpdated(true);
    }
  };

  const handleQuantityChange = (event) => {
    setQuantity(event.target.value);
  };

  const handleKeyDownQuantityChange = (event) => {
    if(event.key === 'Enter'){
      handleUpdateQuantity();
    }
    else if(event.key === 'Escape'){
      setQuantity(cartItem.quantity);
      setIsQuantityUpdated(false);
    }
  };
  
  return (
    <>
      <img className="product-image" src={cartItem.product.image} />

      <div className="cart-item-details">
        <div className="product-name">{cartItem.product.name}</div>
        <div className="product-price">
          {formatMoney(cartItem.product.priceCents)}
        </div>
        <div className="product-quantity">
          <span>
            Quantity:{" "}
            {
              isQuantityUpdated ? (
                <input className="quantity-input" type="text" value={quantity} onChange={handleQuantityChange} onKeyDown={handleKeyDownQuantityChange} />
              ) : (
                <span className="quantity-label">{cartItem.quantity}</span>
              )
            }
          </span>
          <span className="update-quantity-link link-primary" 
            onClick={handleUpdateQuantity}
          >Update</span>
          <span className="delete-quantity-link link-primary"
            onClick={deleteCartItem}
          >
            Delete
          </span>
        </div>
      </div>
    </>
  );
}
