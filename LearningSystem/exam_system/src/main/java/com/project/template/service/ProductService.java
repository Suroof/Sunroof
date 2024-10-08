package com.project.template.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.project.template.entity.Product;
import com.project.template.dto.ProductDTO;

public interface ProductService extends IService<Product> {
    ProductDTO getProductById(Integer id);
    void saveProduct(ProductDTO productDTO);
    void updateProduct(ProductDTO productDTO);
    void deleteProduct(Integer id);
}
