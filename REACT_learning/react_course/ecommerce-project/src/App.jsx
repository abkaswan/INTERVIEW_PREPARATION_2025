import { Route, Routes } from 'react-router';
import { HomePage } from './pages/HomePage'
import './App.css'

function App() {

  return (
    <Routes>
      <Route index element={<HomePage />} />
      <Route path="checkout" element={<div>checkout this</div>} />
    </Routes>
  )
}

export default App
