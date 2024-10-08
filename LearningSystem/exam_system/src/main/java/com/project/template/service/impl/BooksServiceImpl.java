package com.project.template.service.impl;

import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.project.template.dto.BooksDTO;
import com.project.template.entity.Books;
import com.project.template.mapper.BooksMapper;
import com.project.template.service.BooksService;
import org.springframework.beans.BeanUtils;
import org.springframework.stereotype.Service;

@Service
public class BooksServiceImpl extends ServiceImpl<BooksMapper, Books> implements BooksService {
    @Override
    public BooksDTO getBooksById(Integer id){
        Books books = getById(id);
        if (books != null) {
            BooksDTO booksDTO = new BooksDTO();
            BeanUtils.copyProperties(books, booksDTO);
            return booksDTO;
        }
        return null;
    }

    @Override
    public void addBooks(BooksDTO booksDTO) {
        Books books = new Books();
        BeanUtils.copyProperties(booksDTO, books);
        save(books);
    }

    @Override
    public void updateBooks(BooksDTO booksDTO) {
        Books books = new Books();
        BeanUtils.copyProperties(booksDTO, books);
        updateById(books);
    }

    @Override
    public void deleteBooks(Integer id) {
        removeById(id);
    }
}
